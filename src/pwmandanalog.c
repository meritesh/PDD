//
//#include <stdio.h>
//#include<stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include "pwm_o.h"
//#include "adc.h"
////#include "steppertest.c"
//
//
//
//
//int main()
//{   int dr;                                              // duty ratio of corresponding PWM
//    printf("\n Enter the position for the actuator (0-100): ");
//    scanf("%d",&dr);
//
//	pwm_availability(2);
//	pwm_export(2);
//	pwm_set_period(2,20000000);                          //1 ms freq=1kHz => 1000000   ////  5-12 duty ratio
//	pwm_set_duty_cycle(2,20000000,dr);
//	pwm_enable(2,1);
//
//	pwm_availability(3);
//	pwm_export(3);
//	pwm_set_period(3,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(3,1000000,dr);
//	pwm_enable(3,1);
//	pwm_set_period(3,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(3,1000000,dr);
//	pwm_enable(3,1);
//
//	pwm_availability(1);
//	pwm_export(1);
//	pwm_set_period(1,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(1,1000000,dr);
//	pwm_enable(1,1);
//
//	pwm_availability(0);
//	pwm_export(0);
//	pwm_set_period(0,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(0,1000000,dr);
//	pwm_enable(0,1);
//
//	pwm_availability(4);
//	pwm_export(4);
//	pwm_set_period(4,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(4,1000000,dr);
//	pwm_enable(4,1);
//
//	pwm_availability(5);
//	pwm_export(5);
//	pwm_set_period(5,1000000);                          //1 ms freq=1kHz
//	pwm_set_duty_cycle(5,1000000,dr);
//	pwm_enable(5,1);
//
//	pwm_unexport(0);
//	pwm_unexport(2);
//	pwm_unexport(3);
//	pwm_unexport(1);
//	pwm_unexport(4);
//	pwm_unexport(5);
//
//	float position_feedback_in_V;                        //position feeback in volts wrt (0-3.3V) analog scale
//
//	position_feedback_in_V=adc_read(9);
//	printf("\n Current position direct:%f\n",position_feedback_in_V);
//	float position=(position_feedback_in_V/3.3)*100;     //position feedback in (0-100) reference scale
//    printf("\n Current position:%f\n",position);
//
//    stepper();
//	return 0;
//}
