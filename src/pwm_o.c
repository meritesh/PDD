/*
 * Own PWM code for Vacuum Pump and the linear actuator with separate functioning
 */

#include <stdlib.h>
#include <fcntl.h>
#include <bits/fcntl-linux.h>
#include <unistd.h>
#include "pwm_o.h"

#define STR_BUF 250

void pwm_availability(int chip)
{ char tmp_str[STR_BUF];
	sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/pwm0/enable", chip);
/*
	  if (file_valid (tmp_str))
	  {
	    printf("\n PWM chip %d already exported",chip);
	  }
	  else
	  {
		  printf("\n PWM chip %d available",chip);
	  }
	  */
}

void pwm_export(int chip)
{   int fd;
	char tmp_str[STR_BUF];
	sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/export", chip);

	// export PWM chip
	    fd = open(tmp_str, O_WRONLY);
	    write(fd, "0", 1);
	    close(fd);
	    printf("\n Exported PWM chip %d", chip);
}

void pwm_set_period(int chip, int Period)
{   int fd;
	char tmp_str[STR_BUF], strP[20];
	sprintf(strP, "%d", Period);       //to make the number into string using sprintf function
	printf("\n Period: %s", strP);
	sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/pwm0/period", chip);
	// Input Period of PWM
	    fd = open(tmp_str, O_WRONLY);
	    write(fd,strP, 8);
	    close(fd);
}

void pwm_set_duty_cycle(int chip, int Period, int dratio)
{   int fd;
    int Duty_cycle=((dratio*Period)/100);
    char tmp_str[STR_BUF],strDc[20];

    printf("\n Duty ratio=%d",dratio);

    sprintf(strDc, "%d", Duty_cycle);  //tomake the number into string using sprintf function
    printf("\n Duty Cycle: %s", strDc);

	sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/pwm0/duty_cycle", chip);
	// Input Duty cycle  of PWM
	    fd = open(tmp_str, O_WRONLY);
	    write(fd,strDc, 8);
	    close(fd);
}

void pwm_enable(int chip, int enable)
{   int fd;
    char tmp_str[STR_BUF],E[2];
    sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/pwm0/enable", chip);

    sprintf(E, "%d",enable);  //tomake the number into string using sprintf function

    // Enable the PWM signal
    fd = open("/sys/class/pwm/pwmchip2/pwm0/enable", O_WRONLY);
    write(fd,E, 2);
    close(fd);
    if (enable==1)
    printf("\n PWM chip %d is enabled\n",chip);
    else if (enable==0)
    printf("\n PWM chip %d is disabled\n",chip);
    else
    	printf("\n Incorrect input");
}

void pwm_unexport(int chip)
{   int fd;
	char tmp_str[STR_BUF];
	sprintf (tmp_str, "/sys/class/pwm/pwmchip%d/unexport", chip);

	// unexport PWM chip
	    fd = open(tmp_str, O_WRONLY);
	    write(fd, "0", 1);
	    close(fd);
	    printf("\n Unexported PWM chip %d\n", chip);
}
