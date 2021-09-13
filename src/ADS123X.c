/*
  V0.2
  ADS123X.cpp - Library for reading from an ADS1232 and ADS1234 24-bit ADC.
  Created by Hamid Saffari @ Jan 2018. https://github.com/HamidSaffari/ADS123X
  Released into the public domain.
*/

#include "ADS123X.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "newgpio.h"
#include<time.h>

#if ARDUINO_VERSION <= 106
    // "yield" is not implemented as noop in older Arduino Core releases, so let's define it.
    // See also: https://stackoverflow.com/questions/34497758/what-is-the-secret-of-the-arduino-yieldfunction/34498165#34498165
    void yield(void) {};
#endif

gpio *pin_DOUT;
gpio *pin_SCLK;
gpio *pin_PDWN;

void beginl(int apin_DOUT, int apin_SCLK, int apin_PDWN){

  gpio *dout = libsoc_gpio_request(apin_DOUT, LS_GPIO_SHARED);
  libsoc_gpio_set_direction(dout, INPUT);
  //pinMode(apin_DOUT, INPUT);

  gpio *sclk = libsoc_gpio_request(apin_SCLK, LS_GPIO_SHARED);
  libsoc_gpio_set_direction(sclk, OUTPUT);
  //pinMode(apin_SCLK, OUTPUT);

  gpio *pdwn = libsoc_gpio_request(apin_PDWN, LS_GPIO_SHARED);
  libsoc_gpio_set_direction(pdwn, OUTPUT);
  //pinMode(apin_PDWN, OUTPUT);

  power_up();
//  pin_DOUT = dout;
//  pin_SCLK = sclk;
//  pin_PDWN = pdwn;

}

//bool ADS123X::is_ready(void)
//{
//  return libsoc_gpio_get_level(pin_DOUT) == LOW;
//}


void power_up(void)
{  gpio *pdwn = libsoc_gpio_request(122, LS_GPIO_SHARED);
libsoc_gpio_set_direction(pdwn, OUTPUT);



	  gpio *sclk = libsoc_gpio_request(114, LS_GPIO_SHARED);
	  libsoc_gpio_set_direction(sclk, OUTPUT);

	  pin_SCLK = sclk;
	  pin_PDWN = pdwn;
  // Set CLK low to get the ADS1231 out of suspend
	  libsoc_gpio_set_level(pin_PDWN, HIGH);
	libsoc_gpio_set_level(pin_SCLK, LOW);
}

void power_down(void)
{

	libsoc_gpio_set_level(pin_PDWN, LOW);
	libsoc_gpio_set_level(pin_SCLK, HIGH);
}

/*
 * Get the raw ADC value. Can block up to 100ms in normal operation.
 * Returns 0 on success, an error code otherwise.
 */
long reada()
{gpio *pdwn = libsoc_gpio_request(122, LS_GPIO_SHARED);
libsoc_gpio_set_direction(pdwn, OUTPUT);
	  gpio *sclk = libsoc_gpio_request(114, LS_GPIO_SHARED);
	  libsoc_gpio_set_direction(sclk, OUTPUT);
	  gpio *dout = libsoc_gpio_request(113, LS_GPIO_SHARED);
	  libsoc_gpio_set_direction(dout, INPUT);


	  pin_DOUT = dout;
	  pin_SCLK = sclk;
	  pin_PDWN = pdwn;
    int i=0;
    u_int8_t value;
    //unsigned long start;
	unsigned int waitingTime;
	unsigned int SettlingTimeAfterChangeChannel=0;

	
	SettlingTimeAfterChangeChannel=55; // if(_speed==FAST)
	//else SettlingTimeAfterChangeChannel=405;


    /* A high to low transition on the data pin means that the ADS1231
     * has finished a measurement (see datasheet page 13).
     * This can take up to 100ms (the ADS1231 runs at 10 samples per
     * second!).
     * Note that just testing for the state of the pin is unsafe.
     */
	 

		waitingTime=20; //if(_speed==FAST)
		//else waitingTime=150;

	waitingTime+=SettlingTimeAfterChangeChannel;

	waitingTime+=600; //[ms] Add some extra time ( sometimes takes longer than what datasheet claims! )
	
//    start=clock();
//    while(libsoc_gpio_get_level(pin_DOUT) != HIGH)
//    {
//        if(clock()-start > waitingTime)
//            return TIMEOUT_HIGH; // Timeout waiting for HIGH
//    }
//
//    start=clock();
//    while(libsoc_gpio_get_level(pin_DOUT) != LOW)
//    {
//        if(clock()-start > waitingTime)
//            return TIMEOUT_LOW; // Timeout waiting for LOW
//    }

    // Read 24 bits
    for(i=23 ; i >= 0; i--) {
    	libsoc_gpio_set_level(pin_SCLK, HIGH);
        value = (value << 1) + libsoc_gpio_get_level(pin_DOUT);
        libsoc_gpio_set_level(pin_SCLK, LOW);
    }

	
    /* Bit 23 is acutally the sign bit. Shift by 8 to get it to the
     * right position (31), divide by 256 to restore the correct value.
     */
    value = (value << 8) / 256;

	//if(!Calibrating){
		/* The data pin now is high or low depending on the last bit that
		 * was read.
		 * To get it to the default state (high) we toggle the clock one
		 * more time (see datasheet).
		 */
		libsoc_gpio_set_level(pin_SCLK, HIGH);
		libsoc_gpio_set_level(pin_SCLK, LOW);
	//}
    return value; // Success
}

 float read_average(int times) {

	long sum = 0;
	//ERROR_t err;
	for (char i = 0; i < times; i++) {
		long val = reada();
		sum += val;
		yield();

	}
	//if(times==0) return DIVIDED_by_ZERO;
	float value = (float)sum / times;
	return value;
}
