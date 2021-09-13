#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

float encoderPosition;
float adcvalue;
float m_tare;
int m,n,o = 1;

int main(){
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
				carouselrotation(); //angle is of 0
				//loadcellactuatorup;
				//measure m_tare for that bin
				//loadcellactuatordown;
				carouselrotation();  //angle to gate
				//open and then close gate
				// update details in database upon success
				break;
			}
		case 1:
			{
				initialise();
				carouselrotationtogate();
				//open and then close gate
				//edit local databse
				break;
			}
		case 2:
			{
				initialise();
				carouselrotationtogate();
				//open and then close gate
			}
		}
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
				printlf("\nEnter your passcode : 1234");
				initialise();
				carouselrotation(binangle[i]);//put in angle here
				//loadcellup
				//while(potentiometer >= our expected value)
				//read the m_ tare value and set it by using loadcellRead
				pillpickup();

				pilldispence();
				break;
			}
		case 2:
			{
				//snoozecode
				//minutes to seconds
				delay(5); //this is 5 seconds
				m=0;
				break;
			}
		}
	}
}

	//if offline then these things

	pwmset(3, 50);
	servoset(2, 90);

	adcvalue = getadcvalue(9);
	float encoderPosition = getPositionSPI();
	carouselRotation(5);						//enter any float
    m_tare = loadcellread(5);
	return 0;


}





void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


float numberofpills()
{
  float n = ((m_tare - loadcellread(4)) / pillWeight[i]);
  //Serial.println(n);
  //Serial.print(m_tare);
  return n;
}



