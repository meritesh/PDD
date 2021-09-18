//
//#include <stdio.h>
//#include<stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include "Stepper.h"
//  int step_number = 0;
//  float encoderPosition;
//
//int main()
//{gpio *pin_1 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
//gpio *pin_2 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
//	StepperInit(1600,113,114);
//	unsigned long step_delay = setSpeed(3200);
//	//printf("\n%ld \n",step_delay);
//	step_number = step(1600, step_delay, step_number,pin_1, pin_2);
//	int k = 1;
//
//	for (int i=0;i<1600;i++)
//	{
//
//		printf("%d\n",step_number);
//		step_number = step(2, step_delay, step_number, pin_1, pin_2);
//		encoderPosition = getPositionSPI();
//		k=k+1;
//		printf("sadgsadg");
//	}
//
//	return 0;
//
//}
