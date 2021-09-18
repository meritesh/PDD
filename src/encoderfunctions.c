
/*
 * SPI testing utility (using spidev driver)
 *
 * Copyright (c) 2007  MontaVista Software, Inc.
 * Copyright (c) 2007  Anton Vorontsov <avorontsov@ru.mvista.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */
#include "encoderfunctions.h"
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static void pabort(const char *s)
{
	perror(s);
	abort();
}

static const char *device = "/dev/spidev0.0";
static uint32_t mode = 0;
static uint8_t bits = 8;
static uint32_t speed = 500000;
static uint16_t delay = 3;
static int verbose;

uint16_t ans;
uint8_t default_tx[] = {
	0x00
};

uint8_t default_rx[ARRAY_SIZE(default_tx)] = { };
char *input_tx;

int fda;

static void hex_dump(const void *src, size_t length, size_t line_size, char *prefix)
{
	int i = 0;
	const unsigned char *address = src;
	const unsigned char *line = address;
	unsigned char c;

	printf("%s | ", prefix);
	while (length-- > 0) {
		printf("%02X ", *address++);
		if (!(++i % line_size) || (length == 0 && i % line_size)) {
			if (length == 0) {
				while (i++ % line_size)
					printf("__ ");
			}
			printf(" | ");  /* right close */
			while (line < address) {
				c = *line++;
				printf("%c", (c < 33 || c == 255) ? 0x2E : c);
			}
			printf("\n");
			if (length > 0)
				printf("%s | ", prefix);
		}
	}
}

/*
 *  Unescape - process hexadecimal escape character
 *      converts shell input "\x23" -> 0x23
 */
static int unescape(char *_dst, char *_src, size_t len)
{
	int ret = 0;
	char *src = _src;
	char *dst = _dst;
	unsigned int ch;

	while (*src) {
		if (*src == '\\' && *(src+1) == 'x') {
			sscanf(src + 2, "%2x", &ch);
			src += 4;
			*dst++ = (unsigned char)ch;
		} else {
			*dst++ = *src++;
		}
		ret++;
	}
	return ret;
}

static void transfer(int fd, uint8_t const *tx, uint8_t const *rx, size_t len)
{
	int ret;

	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = len,
		.delay_usecs = delay,
		.speed_hz = speed,
		.bits_per_word = bits,
		.cs_change = 0,
	};

	if (mode & SPI_TX_QUAD)
		tr.tx_nbits = 4;
	else if (mode & SPI_TX_DUAL)
		tr.tx_nbits = 2;
	if (mode & SPI_RX_QUAD)
		tr.rx_nbits = 4;
	else if (mode & SPI_RX_DUAL)
		tr.rx_nbits = 2;
	if (!(mode & SPI_LOOP)) {
		if (mode & (SPI_TX_QUAD | SPI_TX_DUAL))
			tr.rx_buf = 0;
		else if (mode & (SPI_RX_QUAD | SPI_RX_DUAL))
			tr.tx_buf = 0;
	}

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1)
		pabort("can't send spi message");

	if (verbose)
		hex_dump(tx, len, 32, "TX");
	hex_dump(rx, len, 32, "RX");
}


float getPositionSPI()
{//int argc; char *argv[];
	int fd;


	fd = open("/sys/class/gpio/export", O_WRONLY);
	    write(fd, "121", 3);
	    close(fd);

	    // Configure as output
	    fd = open("/sys/class/gpio/gpio121/direction", O_WRONLY);
	    write(fd, "out", 3);
	    close(fd);
	    fd = open("/sys/class/gpio/gpio121/value", O_WRONLY | O_SYNC);
	        write(fd, "1", 1);
	        close(fd);
	int ret = 0;

	uint8_t *tx;
	uint8_t *rx;
	int size;

	//parse_opts(argc, argv);

	fd = open(device, O_RDWR);
	if (fd < 0)
		pabort("can't open device");

	/*
	 * spi mode
	 */
	ret = ioctl(fd, SPI_IOC_WR_MODE32, &mode);
	if (ret == -1)
		pabort("can't set spi mode");

	ret = ioctl(fd, SPI_IOC_RD_MODE32, &mode);
	if (ret == -1)
		pabort("can't get spi mode");

	/*
	 * bits per word
	 */
	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't set bits per word");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		pabort("can't get bits per word");

	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't set max speed hz");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		pabort("can't get max speed hz");

	printf("spi mode: 0x%x\n", mode);
	printf("bits per word: %d\n", bits);
	printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);

	if (input_tx) {
		size = strlen(input_tx+1);
		tx = malloc(size);
		rx = malloc(size);
		size = unescape((char *)tx, input_tx, size);
		transfer(fd, tx, rx, size);
		free(rx);
		free(tx);
	} else {

		fda = open("/sys/class/gpio/gpio121/value", O_WRONLY | O_SYNC);
			        write(fda, "0", 1);
			        close(fda);
		transfer(fd, default_tx, default_rx, sizeof(default_tx));
	}
ans = default_rx[0] << 8;
		fda = open("/sys/class/gpio/gpio121/value", O_WRONLY | O_SYNC);
			        write(fda, "0", 1);

		transfer(fd, default_tx, default_rx, sizeof(default_tx));
		write(fda, "1", 1);
					        close(fda);

bool binaryArray[16];
ans |= default_rx[0];
for(int i = 0; i < 16; i++) binaryArray[i] = (0x01) & (ans >> (i));
if ((binaryArray[15] == !(binaryArray[13] ^ binaryArray[11] ^ binaryArray[9] ^ binaryArray[7] ^ binaryArray[5] ^ binaryArray[3] ^ binaryArray[1]))
          && (binaryArray[14] == !(binaryArray[12] ^ binaryArray[10] ^ binaryArray[8] ^ binaryArray[6] ^ binaryArray[4] ^ binaryArray[2] ^ binaryArray[0])))
    {
      //we got back a good position, so just mask away the checkbits
      ans &= 0x3FFF;
    }
  else
  {
    ans = 0xFFFF; //bad position
  }
//printf("%d\n", ans);
//printf("%04X \n", ans);
ans &= 0x3FFF;
//printf("%04X \n", ans);
//printf("%d\n", ans);
	close(fd);
	ans = ans >> 2;
	float currentPositionaa = ans * 0.088;
	printf("%f\n", currentPositionaa);

	return currentPositionaa;
}



