

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "adc.h"

#define STR_BUF 250

void adc_sampling_frequency_availability()
{
	int fd;
	char tmp_str[STR_BUF];

	fd = open("/sys/bus/iio/devices/iio\:device0/sampling_frequency_available", O_RDONLY);
	read(fd,tmp_str, 20);
	printf("Available Sampling Frequencies: %s\n", tmp_str);
	close(fd); //close value file
}

void adc_in_voltage_sampling_frequency()
{
	int fd;
    char tmp_str[STR_BUF];

    fd = open("/sys/bus/iio/devices/iio\:device0/in_voltage_sampling_frequency", O_RDONLY);
    read(fd,tmp_str, 20);
    printf("In Voltage Sampling Frequency: %s\n", tmp_str);
    close(fd); //close value file
}

void adc_set_in_voltage_sampling_frequency(int new_frequency)
{
	int fd;
    char tmp_str[STR_BUF],strF[20];

    sprintf(strF,"%d",new_frequency);

    fd = open("/sys/bus/iio/devices/iio\:device0/in_voltage_sampling_frequency",O_WRONLY);
    write(fd,strF,20);
    close(fd);
    printf("In Voltage Sampling Frequency: %s\n", tmp_str);
    close(fd); //close value file
}

float adc_read(int adc_number)
{
	int fd;
    char tmp_str1[STR_BUF],tmp_str2[STR_BUF];

    sprintf(tmp_str1,"/sys/bus/iio/devices/iio\:device0/in_voltage%d_raw",adc_number);
    fd = open(tmp_str1, O_RDONLY);
    read(fd,tmp_str2, 20);
    printf("Analog Input: %s\n", tmp_str2);
    close(fd); //close value file
    float x = atoi(tmp_str2);      //return string to integer
    float y=(x/4096)*3.3;
	return y;       //Converting to Analog output scale 0-3.3V from 0-4096 scale
}
