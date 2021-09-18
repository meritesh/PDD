//#include <stdio.h>
//#include<stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>
#include "pwm_o.h"
#include "adc.h"


void pwmset(int pinnumber, int dr){
	if(dr > 250)
		dr = 100;

	pwm_availability(pinnumber);
		pwm_export(pinnumber);
		pwm_set_period(pinnumber,1000000);                          //1 ms freq=1kHz => 1000000   ////  5-12 duty ratio
		pwm_set_duty_cycle(pinnumber,1000000,dr);
		pwm_enable(pinnumber,1);
		pwm_unexport(pinnumber);
}

void servoset(int pinnumber, int degree){
	int dr = 0;
	if(dr<181){
		float temp = degree/22.5;  ///25.71 for 7
		dr = abs(temp);
		dr = 5 + dr;
	}
	else
		dr = 0;
	pwm_availability(pinnumber);
		pwm_export(pinnumber);
		pwm_set_period(pinnumber,20000000);                          //1 ms freq=1kHz => 1000000   ////  5-12 duty ratio
		pwm_set_duty_cycle(pinnumber,20000000,dr);                   //// dr should be between 5 to 12
		pwm_enable(pinnumber,1);
		pwm_unexport(pinnumber);
}

//float getadcvalue(int pinNumber){
//		float position_feedback_in_V;                        //position feeback in volts wrt (0-3.3V) analog scale
//		position_feedback_in_V=adc_read(pinNumber); 			     ///////// this is in 0-3.3 range
//		return position_feedback_in_V;
//}
