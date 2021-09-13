void initialise(){
	//
    //analogWrite(pwm_z_pin, 255);
    //analogWrite(pwm_a_pin, 0);
    //analogWrite(pwm_v_pin, 0);
    //servo.write(90);
    delay(500);
}


poweronpump(float pillweight)
{
	if (pillType[i] == 0) { //tablet
	if (pillWeight[i] > 0.4) {
	                  pumppower = 255; //For pills with weight > 400mg, Voltage should be 12V
	                }

	else {
	                  pumppower = 165 + (pillWeight[i] / 0.4) * 90; //For pills in between 0 mg to 400 mg, voltage should vary linearly from 7V to 12V
	                }
	sensitivity = pillWeight[i] * 10;
	              }

	else if (pillType[i] == 1) { //capsule
	                pumppower = 255;
	                sensitivity = 0.5;
	              }

	//analogWrite(pwm_v_pin, pumppower);
	}



pillpickfunction()
{    float m_live = loadcellread(4);
	float p_live = pressureRead();
	analogWrite(pwm_z_pin, 0); //probedown
    while ((p_live < 40 ) && ((m_live - m_tare) < sensitivity)) //((m_live-m_tare) > 10)            //probe will go down untill the there's a difference in loadcell OR pressure
    { m_live = loadcellread(4);
      //Serial.print ("The live mass is : "); //Serial.println(m_live);
      p_live = pressureRead();
      analogWrite(pwm_z_pin, 0);

    }
    //starts upward motion after this
    analogWrite(pwm_z_pin, 255);
    analogWrite(pwm_v_pin, 255); //this is maybe not needed
}





int tempfunctiontobenamed()
{
	if (k > 0.7 && k < 1.3)                 //30 percent tolerence
	{
	                delay (2000);
	                //while(analogRead(pwm_z_pin_sen)<100){delay(100);}
	                m_tare = loadcellread(4);
	                trynumber = 0;
	                //Serial.println("One pill only, success");
	                return 0;
	}

    else if (k > 1.3)
    {
      //Serial.println("More than One pill");
      analogWrite(pwm_v_pin, 0);
      delay (3000);
      n = 4;    m = 3;                            //Case 4 : probe down
      trynumber = 0;
      pillpickup();
    }
    else
    {
    	servotry();
    	if (trynumber < 4)
    	{
    		pillpickup();
    	}
    	else
    		carouselshake();
    		trynumber = 0;
    		pillpickup();
    }
}


pillpickup()
{
					poweronpump();//give in pill weight as input and bool type from API
					pillpickfunction();
					m_live = loadcellread(4);
					float k = numberofpills(); //takes selected pill's weight
					tempfunctiontobenamed(); //takes k
}


pilldispence()
{
				//Serial.println("Carousel rotation for dispensing pill");
	              analogWrite(lcellacc, 0);
	              delay (2000);
	              encoderPosition = getPositionSPI(ENC_0, RES12);
	              carouselRotation(dispenseAngle);
	              delay(500);
	              analogWrite(pwm_v_pin, 0);
	              delay(3000);
	              Serial.println("Dispense succesful");
}
