//
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include "newgpio.h"
//
//#define OUTPUT 1
//#define INPUT 0
//
//
//int main()
//{// check with 121 as the number, 2nd from bottom on left side
//	int GPIO_INPUT;
//while(1){
//
//	printf("\n Enter GPIO(linux) pin number:");
//	scanf("%d",&GPIO_INPUT);
//
//	gpio *gpio_input;
//
//	gpio_input = libsoc_gpio_request(GPIO_INPUT, LS_GPIO_SHARED);
//
//	  if (gpio_input == NULL)
//	  {
//		  printf("GPIO not exported\n");
//	   	  }
//	  // Set direction to INPUT
//	  libsoc_gpio_set_direction(gpio_input, OUTPUT); // INPUT -> OUTPUT
//
//	  // Check the direction
//	  if (libsoc_gpio_get_direction(gpio_input) != OUTPUT) // INPUT -> OUTPUT
//	  {
//	    printf("Failed to set direction to INPUT\n");
//	    }
//
//	  //printf("\n GPIO level is:%d\n",libsoc_gpio_get_level(gpio_input));
//
//	  libsoc_gpio_set_level(gpio_input, 1);
//
//}
//    return 0;
//}
