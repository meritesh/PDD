#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "Stepper.h"
#include <stdbool.h>
int step_number = 0;
float encoderPosition;
void steppermove(int movethissteps)
{
	StepperInit(1600,113,114);
	unsigned long step_delay = setSpeed(3200);
	printf("\n%ld \n",step_delay);
	step_number = step(movethissteps, step_delay, step_number);

}

void carouselRotation(float a)
{  bool dir = true;
step_number = 0;
  encoderPosition = getPositionSPI(); int bb;
  //Serial.println(encoderPosition);
  if (a - encoderPosition) {bb = 1;}
  else if (a == encoderPosition) {int steps = 0; }
  else {bb = -1;}
  int steps = 0.9 * abs((a - encoderPosition)) * (1600 / 360);
  steps = bb * steps;
  steppermove(steps);
  //stepper.runToPosition();
  //stepper.setCurrentPosition(0);
  step_number = 0;
  encoderPosition = getPositionSPI();
  int xx= 0;

  while (!((getPositionSPI() > (a - 0.25)) && (getPositionSPI() < (a + 0.25))))
   {
    encoderPosition = getPositionSPI();
    if(getPositionSPI()>a)
    {dir =false;}
    //Serial.println(encoderPosition);Serial.println(dir);}
    else{dir = true; //Serial.println(encoderPosition);Serial.println(dir);
    }
    encoderPosition = getPositionSPI();
    //Serial.println(encoderPosition);
    steppermove(xx);
//    stepper.setMaxSpeed(1600);                                                                                                     // steps per second
//    stepper.setAcceleration(3200);                                                                                                 // steps per second per second
//    stepper.runToPosition();
    if(dir){xx = xx + 1;}
    else xx=xx - 1;

    }
}

void carouselshake()
{
	analogWrite(pwm_v_pin, 0);                                                                                       // LC actuator should move down before shaking
	              analogWrite(lcellacc, 0);
	              delay(2500);
	              stepper.setCurrentPosition(0);
	              // stepper.setMaxSpeed(2000);
	              // stepper.setAcceleration(10000);
	              for (int i = 0; i < 20; i++)
	              {
	                stepper.moveTo(8);                                                                                      // Since angle is 60 deg, should we rotate between 55 & 65
	                stepper.runToPosition();
	                stepper.moveTo(-6 );                                                                                   //Creating problemm
	                stepper.runToPosition();
	                Serial.println("asdgihlusahdulighuidhl");
	              }
	              stepper.moveTo(0);
	              stepper.runToPosition();
	              delay(500);
	              // analogWrite(lcellacc, 230);
	              // delay(5000);
	              // m_tare = loadcellread(4);
	              Serial.println("Shaking done");
}
