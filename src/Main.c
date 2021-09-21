#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "adc.h"
#include "encoderfunctions.h"
#include "ADS123X.h"
//#include "newgpio.h"

float encoderPosition;
float adcvalue;
float m_tare;
int k;
int pumppower;
int trynumber;
float sensitivity;
float m_live;
float pillWeight = 0.880;
int m,n,o = 1;
const float binAngle[11] = { 26.92, 60.25, 92.84, 125.70, 156.67, 191.66, 224.48, 257.41, 290.31, 322.8, 355.29};//158.53






#include "ADS123X.h"
///////////////////////////////////////


float loadcellread(int n,gpio *a,gpio *b,gpio *c) {
  //beginl(113, 114, 122);
  float value = read_average(n,a,b,c);                   //Moving average of n sample
  float mass = value - 649029;
  mass = mass / 9866.025;
  printf("\n %f This is the mass",mass);
  return mass;
}


//////////////////




#include "Stepper.h"
#include <stdbool.h>
int step_number = 0;
float encoderPosition;
void steppermove(int movethissteps,gpio *pin_1,gpio *pin_2)
{
	//StepperInit(1600,113,114);
	unsigned long step_delay = setSpeed(4000);
	printf("\n%d \n",step_number);
	step_number = step(10000, step_delay, step_number, pin_1, pin_2);

}

void carouselRotation(float a)
{gpio *pin_1 = libsoc_gpio_request(123, LS_GPIO_SHARED);
gpio *pin_2 = libsoc_gpio_request(124, LS_GPIO_SHARED);
libsoc_gpio_set_direction(pin_1, OUTPUT);
libsoc_gpio_set_direction(pin_2, OUTPUT);
	printf("%f\n",a);
	bool dir = true; //bool instead
step_number = 0;
  encoderPosition = getPositionSPI(); int bb = 1;
  //Serial.println(encoderPosition);
  if (a > encoderPosition) {bb = 1;}
  else if (a == encoderPosition) {int steps = 0; }
  else {bb = -1;}
  printf("difference in angle is %f",(a - encoderPosition));
  int steps = 0.9 * abs((a - encoderPosition)) * 8.88;
  printf("we wil do this many %d",steps);
  steps = bb * steps;
  delayc(1000);
  printf("cehck 1");
  steppermove(steps,pin_1,pin_2);
  delayc(50000);
  //stepper.runToPosition();
  //stepper.setCurrentPosition(0);
  step_number = 0;
  encoderPosition = getPositionSPI();
  delayc(5);
  int xx= 0;

  while (!(((encoderPosition > (a - 0.25)) && (encoderPosition < (a + 0.25)))))
   {
	  if(encoderPosition > (a - 0.5))
    //encoderPosition = getPositionSPI();
    if(getPositionSPI()>a)
    {dir =false;}
    //Serial.println(encoderPosition);Serial.println(dir);}
    else{dir = true; //Serial.println(encoderPosition);Serial.println(dir);
    }

    encoderPosition = getPositionSPI();
    //Serial.println(encoderPosition);
    //printf("................ %d ..................",xx);
    steppermove(1,pin_1,pin_2);
    //delayc(100);
//    stepper.setMaxSpeed(1600);                                                                                                     // steps per second
//    stepper.setAcceleration(3200);                                                                                                 // steps per second per second
//    stepper.runToPosition();
    if(dir){xx = xx + 1;}
    else xx=xx - 1;

    }
}


void carouselshake()
{
//				  analogWrite(pwm_v_pin, 0);                                                                                       // LC actuator should move down before shaking
//	              analogWrite(lcellacc, 0);
//	              delay(2500);
//	              stepper.setCurrentPosition(0);
//	              // stepper.setMaxSpeed(2000);
//	              // stepper.setAcceleration(10000);
//	              for (int i = 0; i < 20; i++)
//	              {
//	                stepper.moveTo(8);                                                                                      // Since angle is 60 deg, should we rotate between 55 & 65
//	                stepper.runToPosition();
//	                stepper.moveTo(-6 );                                                                                   //Creating problemm
//	                stepper.runToPosition();
//	                //Serial.println("asdgihlusahdulighuidhl");
//	              }
//	              stepper.moveTo(0);
//	              stepper.runToPosition();
//	              delay(500);
//	              // analogWrite(lcellacc, 230);
//	              // delay(5000);
//	              // m_tare = loadcellread(4);
//	              Serial.println("Shaking done");
}


//void delayc(int number_of_seconds)
//{
//    // Converting time into milli_seconds
//    int milli_seconds = 1000 * number_of_seconds;
//
//    // Storing start time
//    clock_t start_time = clock();
//
//    // looping till required time is not achieved
//    while (clock() < start_time + milli_seconds);
//}




/////////////////
int main(){
	//while(1){float encoderPosition = getPositionSPI();}
	//while(1){
	float loadcellactuator = 0; loadcellactuator = adc_read(0);
	printf("%f loadcellact \n ",loadcellactuator);
//}


	gpio *a = libsoc_gpio_request(113, LS_GPIO_SHARED);
	libsoc_gpio_set_direction(a, OUTPUT);
		  gpio *b = libsoc_gpio_request(114, LS_GPIO_SHARED);
		  libsoc_gpio_set_direction(b, OUTPUT);
		  gpio *c = libsoc_gpio_request(25, LS_GPIO_SHARED);//122
		  libsoc_gpio_set_direction(c, INPUT);
//		  gpio *d = libsoc_gpio_request(122, LS_GPIO_SHARED);//122
//				  libsoc_gpio_set_direction(d, OUTPUT);

	initialise();

	printf("adfas");
	scanf("%d %d", &m, &n);
while(1){
	//turn on relay switch
	//hardwaretestfunction

	//networktest here and other connections

	//switch case here for offline case


switch(n){
//add, refill, remove pills
case 0:
	{
		switch(o)
		{
		case 0://add new pills, we will get bin number, name,type and number of pills as input
			{
				initialise();
				//carouselRotation(); //angle is of 0
				//loadcellactuatorup;
				//measure m_tare for that bin
				//loadcellactuatordown;
				//carouselRotation();  //angle to gate
				//open and then close gate
				// update details in database upon success
				break;
			}
		case 1:
			{
				initialise();
				//carouselRotationtogate();
				//open and then close gate
				//edit local databse
				break;
			}
		case 2:
			{
				initialise();
				//carouselrotationtogate();
				//open and then close gate
			}
		}
	break;
	}
//dispense pills
case 1:
	{
		switch(m){

		case 0:
			{
				printf("chose 1 for dispense now and 2 for snooze");
				scanf("%d",&m);
				break;
			}

		case 1:
			{
				printf("\nEnter your passcode : 1234");
				initialise();
				loadcellactuator = adc_read(0);
				int i = 4;
				carouselRotation(binAngle[i]);//put in angle here
				pwmset(3, 100);
				printf("waiting\n");
				//delayc(50000);
				//libsoc_gpio_set_level(d, HIGH);
				loadcellactuator = adc_read(0);
				while(loadcellactuator > 0.2){loadcellactuator = adc_read(0);
				//printf("%f loadcellact \n ",loadcellactuator);
				}
				//read the m_ tare value and set it by using loadcellRead
				m_tare = loadcellread(4,a,b,c);
				m_tare = loadcellread(4,a,b,c);
				printf("%f ............. this is m_tare value\n",m_tare);
				pillpickup(a,b,c);
				printf("pill is picked");
				delayc(10);
				pilldispence();
				break;
			}
		case 2:
			{
				//snoozecode
				//minutes to seconds
				delayc(5); //this is 5 seconds
				m=0;
				break;
			}
		}
	break;
	}
}

	//if offline then these things



}
adcvalue = getadcvalue(9);
float encoderPosition = getPositionSPI();
//carouselRotation(5);						//enter any float
m_tare = loadcellread(5,a,b,c);
	return 0;


}








float numberofpills(gpio *a,gpio *b, gpio *c)
{
  float n = ((m_tare - loadcellread(4,a,b,c)) / pillWeight);
  //Serial.println(n);
  //Serial.print(m_tare);
  return n;
}


























///////////////////////////////////////////////

//
//getadcvalue(int pinNumber){
//		float position_feedback_in_V;                        //position feeback in volts wrt (0-3.3V) analog scale
//		position_feedback_in_V=adc_read(pinNumber); 			     ///////// this is in 0-3.3 range
//		return position_feedback_in_V;
//}






float pressureRead() {
  float voltage = 0;
  voltage = adc_read(8);
  //float voltage = p_sensorValue * (3.3 / 1023.0);
  printf("\n %f-> value\n",voltage);
  float Pressure = (2.50 - voltage) * 70 / 2;
  //Serial.print("The pressure is : ");
  printf("\n %f == pressure",Pressure);
  return Pressure;
}








void initialise(){

    pwmset(2, 100);
    pwmset(3, 0);
    pwmset(1, 0);
    servoset(4, 90);
    delayc(500);
}


void poweronpump(float pillWeight)
{
int pillType = 0;
	if (pillType == 0) { //tablet
	if (pillWeight > 0.4) {
	                  pumppower = 100; //For pills with weight > 400mg, Voltage should be 12V
	                }

	else {
	                  pumppower = 65 + (pillWeight / 0.4) * 35.2; //For pills in between 0 mg to 400 mg, voltage should vary linearly from 7V to 12V
	                }
	sensitivity = pillWeight * 10;
	              }

	else if (pillType == 1) { //capsule
	                pumppower = 100;
	                sensitivity = 0.5;
	              }

	pwmset(1, pumppower);
	}



void pillpickfunction(gpio *a,gpio *b,gpio *c)
{


	m_live = loadcellread(4,a,b,c);
	float p_live = pressureRead();//pressure read
	pwmset(2, 0); //probedown
	printf("...............in actuator function ................");
    while ((p_live < 50 ) && ((m_live - m_tare) < sensitivity)) //((m_live-m_tare) > 10)            //probe will go down untill the there's a difference in loadcell OR pressure
    { m_live = loadcellread(4,a,b,c);
      //Serial.print ("The live mass is : "); //Serial.println(m_live);
      p_live = pressureRead();
      printf("\n%f %f ................  pressure sensor and mass valie",p_live,m_live);
    }
    //starts upward motion after this
    pwmset(2, 100);
    //analogWrite(pwm_v_pin, 255); //this is maybe not needed
}




int tempfunctiontobenamed(float k,gpio *a,gpio *b,gpio *c)
{
	if (k > 0.7 && k < 1.3)                 //30 percent tolerence
	{
	                delayc(50000);
	                //while(analogRead(pwm_z_pin_sen)<100){delay(100);}
	                m_tare = loadcellread(4,a,b,c);
	                trynumber = 0;
	                printf("One pill only, success\n");
	                delayc(50000);
	                return 0;
	}

    else if (k > 1.3)
    {
      //Serial.println("More than One pill");
    	printf("ore than One pill\n");
    		                delayc(50000);
     pwmset(1, 0);
      delayc(50); // can add close loop here
      //n = 4;    m = 3;                            //Case 4 : probe down
      trynumber = 0;
      pillpickup(a,b,c);
      return 0;
    }
    else
    {    	printf("no pill\n");
    delayc(50000);
    	//servotry();
    	if (trynumber < 4)
    	{
    		pillpickup(a,b,c);
    	}
    	else
    		{carouselshake();
    		trynumber = 0;
    		pillpickup();
    		return 0;}
    }
}


void pillpickup(gpio *a,gpio *b,gpio *c)
{
					poweronpump(pillWeight);//give in pill weight as input and bool type from API
					pillpickfunction(a,b,c);
					//delayc(20000);//20000 == 2 sec
					float linearactuator = adc_read(0);
					while(linearactuator > 1){linearactuator = adc_read(0);
									printf("%f linear \n ",linearactuator);}
					m_live = loadcellread(4,a,b,c);
					printf("....... %f .....................................2.......................\n.",m_tare);
					//float k = numberofpills(a,b,c);
					float k = ((m_tare - m_live) / pillWeight);
					printf("............................................3........................\n");
					printf("%f  %f  m tare live value\n",m_tare, m_live);
					printf("%f  %f k and m tare minus live value\n",k,(m_tare - m_live));//takes selected pill's weight
					tempfunctiontobenamed(k,a,b,c); //takes k
}


void pilldispence()
{
				//Serial.println("Carousel rotation for dispensing pill");
					printf("..........................................................now dispencsing\n.............\n..............\n..........");
				  pwmset(3, 0);
	              delayc(20000);
	              encoderPosition = getPositionSPI();
	              carouselRotation(binAngle[0]);
	              delayc(5000);
	              pwmset(1, 0);
	              delayc(30000);
	              printf("Dispense succesful");
}






//
//int main()
//{while(1)
//	{float encoderPosition = getPositionSPI();}
//return 0;
//}


////////////////
//#include <stdio.h>
//#include<stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>

