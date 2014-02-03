/*
*	REMOTE CONTROL XBEE DATA TELLER
*
*	Use: 4 - buttons (8 chcracters)
*	Forward-i, Backward-k, Left-j, Right-l
*	Capital for key held down, small for key lifted up
*
*
*	Copyright(C) 2011, SmoothRC
*	Subhajit Sahu, LowVolt Group
*
*/


#include	<avr/io.h>
#include	<util/delay.h>


//Function declarations
void GetXbeeData(void);



//Constants
#define				_fwdOn			'I'



//Global Variables
char	rFORWARD, rBACKWARD, rLEFT, rRIGHT;



void GetXbeeData()
	{
	
	}




	
