
#include "Stepper.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "newgpio.h"
#include<time.h>


int pin_count =2;
int motor_pin_1 = 123;
int motor_pin_2 = 124;
unsigned long last_step_time = 0;
int direction = 0;
int number_of_steps = 1600;
unsigned long step_delay;

/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */
void StepperInit(int number_of_steps, int motor_pin_1, int motor_pin_2)
{
  //this->step_number = 0;    // which step the motor is on
  //this->last_step_time = 0; // timestamp in us of the last step taken
 // total number of steps for this motor

  gpio *pin_1 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
  libsoc_gpio_set_direction(pin_1, OUTPUT);

  gpio *pin_2 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
  libsoc_gpio_set_direction(pin_2, OUTPUT);


}


unsigned long setSpeed(long whatSpeed) //3200
{
  step_delay = 60L * 1000L * 1000L / number_of_steps / whatSpeed;
  return step_delay;// ****be careful
}

/*
 * Moves the motor steps_to_move steps.  If the number is negative,
 * the motor moves in the reverse direction.
 */
int step(int steps_to_move, unsigned long step_delay, int step_number,gpio *pin_1,gpio *pin_2)
{unsigned long last_step_time = 0;
  int steps_left = abs(steps_to_move);  // how many steps to take
  int direction = 0;
  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { direction = 1; }
  if (steps_to_move < 0) { direction = 0; }

//  gpio *pin_1 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
//  gpio *pin_2 = libsoc_gpio_request(motor_pin_1, LS_GPIO_SHARED);
  // decrement the number of steps, moving one step each time:
  while (steps_left > 0)
  {
    unsigned long now = clock();
    //printf("\n%lld\n",now);
    // move only if the appropriate delay has passed:
    if (now - last_step_time >= step_delay) //now - this->last_step_time >= step_delay      ////********
    {
      // get the timeStamp of when you stepped:
      last_step_time = now;                        ////***
      // increment or decrement the step number,
      // depending on direction:
      if (direction == 1)
      {
        step_number++;
        if (step_number == number_of_steps) {
          step_number = 0;
        }
      }
      else
      {
        if (step_number == 0) {
          step_number = number_of_steps;
        }
        step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, ..., {3 or 10}
	  libsoc_gpio_set_direction(pin_1, OUTPUT);


	  libsoc_gpio_set_direction(pin_2, OUTPUT);
      stepMotor(step_number % 4, pin_1, pin_2);
    }

  }
  return step_number;
}

/*
 * Moves the motor forward or backwards.
 */

void stepMotor(int thisStep, gpio *pin_1, gpio *pin_2)
{

//printf("%d <- this step",thisStep);


  if (pin_count == 2) {
    switch (thisStep) {
      case 0:  // 01
    	libsoc_gpio_set_level(pin_1, LOW);
    	libsoc_gpio_set_level(pin_2, HIGH);
//        digitalWrite(motor_pin_1, LOW);
//        digitalWrite(motor_pin_2, HIGH);
      break;
      case 1:  // 11
      	libsoc_gpio_set_level(pin_1, HIGH);
      	libsoc_gpio_set_level(pin_2, HIGH);
//        digitalWrite(motor_pin_1, HIGH);
//        digitalWrite(motor_pin_2, HIGH);
      break;
      case 2:  // 10
      	libsoc_gpio_set_level(pin_1, HIGH);
      	libsoc_gpio_set_level(pin_2, LOW);
//        digitalWrite(motor_pin_1, HIGH);
//        digitalWrite(motor_pin_2, LOW);
      break;
      case 3:  // 00
      	libsoc_gpio_set_level(pin_1, LOW);
      	libsoc_gpio_set_level(pin_2, LOW);
//        digitalWrite(motor_pin_1, LOW);
//        digitalWrite(motor_pin_2, LOW);
      break;
    }
  }
}
