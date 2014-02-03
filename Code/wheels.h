/*
*	SMOOTH REMOTE CONTROLLED BOT WHEEL DRIVER
*
*	Use: + velocity = forward, - velocity = backward
*
*
*	Copyright(C) 2011, SmoothRC
*	Subhajit Sahu, LowVolt Group
*
*/


#include	<avr/io.h>
#include	<util/delay.h>
#include	<math.h>

//Function declarations
void DriveWheels(void);



//Constants
#define				_wTimeMax			1
#ifndef				WHEELS
#define				WHEELS				PORTC
#endif




//Global Variables
int		wLEFT, wRIGHT;
int		wTime;



//to be call by timer interrupt of very small time interval
void	DriveWheels()
	{
	if(wTime)wTime--; else wTime = _wTimeMax;
	WHEELS = (WHEELS & 0b11110000) | (((wTime<abs(wLEFT))?((wLEFT>0)?0b1000:0b0100):0b0000) | ((wTime<abs(wRIGHT))?((wRIGHT>0)?0b10:0b01):0b00));
	}


