//#include <stdio.h>
//#include "ADS123X.h"
/////////////////////////////////////////
//
//
//float loadcellread(int n,gpio *a,gpio *b,gpio *c) {
//
//  float value = read_average(n,a,b,c);                   //Moving average of n sample
//  float mass = value - 649029;
//  mass = mass / 9866.025;
//  printf("\n %f This is the mass",mass);
//  printf("\n %f This is the value",value);
//  return mass;
//}
////#define SCALE_DOUT   12
////#define SCALE_SCLK   13;
////#define SCALE_PDWN   9;
//
//int main(int argc, char *argv[])
//{
//	gpio *a = libsoc_gpio_request(113, LS_GPIO_SHARED);
//		libsoc_gpio_set_direction(a, OUTPUT);
//			  gpio *b = libsoc_gpio_request(114, LS_GPIO_SHARED);
//			  libsoc_gpio_set_direction(b, OUTPUT);
//			  gpio *c = libsoc_gpio_request(25, LS_GPIO_SHARED);
//			  libsoc_gpio_set_direction(c, INPUT);
//
//	//beginl(113, 114, 122);
//int k = 5;
//while(1){
//loadcellread(5,a,b,c);
////delayc(1000);
//	//printf("%d",k);
//}
//	return 0;
//}
//
//
//
//
