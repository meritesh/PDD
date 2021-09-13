/*
  V0.2
  ADS123X.h - Library for reading from an ADS1232 and ADS1234 24-bit ADC.
  Created by Hamid Saffari @ Jan 2018. https://github.com/HamidSaffari/ADS123X
  Released into the public domain.
*/
//#ifndef ADS123X_h
//#define ADS123X_h
//
//#if ARDUINO >= 100
//#include "Arduino.h"
//#else
////#include "WProgram.h"
//#endif

//======================== which one? ========================
//#define ADS1232
#define ADS1234
//============================================================

//typedef enum ERROR_t {
//	NoERROR,
//	TIMEOUT_HIGH,     // Timeout waiting for HIGH
//	TIMEOUT_LOW,      // Timeout waiting for LOW
//	WOULD_BLOCK,      // weight not measured, measuring takes too long
//	STABLE_TIMEOUT,   // weight not stable within timeout
//	DIVIDED_by_ZERO
//};
//
//typedef enum Gain{
//	GAIN1 = 1,
//	GAIN2,
//	GAIN64,
//	GAIN128
//};
//
//typedef enum Speed{
//	SLOW = 0,
//	FAST
//};

//typedef enum Channel{
//	AIN1 = 1,
//	AIN2 = 2,
//  #if defined ADS1232
//	TEMP = 3,
//  #else if defined ADS1234
//	AIN3 = 3,
//	AIN4 = 4
//  #endif
//};
//
//class ADS123X
//{
//	public:
	
//		ADS123X();
//
//		virtual ~ADS123X();
		
        // Initialize library
        void beginl(int pin_DOUT, int pin_SCLK, int pin_PDWN);


		// check if chip is ready
		// from the datasheet: When output data is not ready for retrieval, digital output pin DOUT is high. Serial clock
		// input PD_SCK should be low. When DOUT goes to low, it indicates data is ready for retrieval.
		//_Bool? is_ready();
			
		// set the gain factor; takes effect only after a call to read()
		
		// waits for the chip to be ready and returns a reading
		//long long int read();

		// returns an average reading; times = how many times to read
		float read_average(int times);
		
		// returns (read_average() - OFFSET), that is the current value without the tare weight; times = how many readings to do
		

		// puts the chip into power down mode
		void power_down();

		// wakes up the chip after power down mode
		void power_up();

//
//	private:
//		int _pin_DOUT;
//		int _pin_SCLK;
//		int _pin_PDWN;
//		int _pin_GAIN0;
//		int _pin_GAIN1;
//		int _pin_SPEED;
//		int _pin_A0;
//		int _pin_A1_or_TEMP;
//
//	  #if defined ADS1232
//		float OFFSET[2] = {};	// used for tare weight
//		float SCALE[2] = {1,1};	// used to return weight in grams, kg, ounces, whatever
//
//	  #else if defined ADS1234
//		float OFFSET[4] = {};	// used for tare weight
//		float SCALE[4] = {1,1,1,1};	// used to return weight in grams, kg, ounces, whatever
//	  #endif
//
//		Speed _speed ;
//		Channel lastChannel = AIN1;
//};

//#endif /* #ifndef ADS123X_h */

