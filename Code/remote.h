/*
*	REMOTE CONTROL STATUS TELLER
*
*	Use: 4 - buttons
*	Forward, Backward, Left, Right
*
*	Req.:
*	External header file "xbee.h"
*	for recieving commands: forward(on/off), backward(on/off), left(on/off), right(on/off)
*
*	Copyright(C) 2011, SmoothRC
*	Subhajit Sahu, LowVolt Group
*
*/


#include	<avr/io.h>
#include	<util/delay.h>
// External header file for recieving XBEE commands
#include	"xbee.h"


//Function declarations
void GetRemoteStatus(void);



//Constants
#define				_fwdOn			'I'
#define				_fwdOff			'i'
#define				_ltOn			'J'
#define				_ltOff			'j'
#define				_bckOn			'K'
#define				_bckOff			'k'
#define				_rtOn			'l'
#define				_rtOff			'L'



//Global Variables
char	rFORWARD, rBACKWARD, rLEFT, rRIGHT;



void GetRemoteStatus()
	{
	char c;
	
	c = GetXbeeData();
	switch(c)
		{
		case _fwdOn:
		rFORWARD = 'a';
		break;
		case _fwdOff:
		rFORWARD = '\0';
		break;
		case _bckOn:
		rBACKWARD = 'a';
		break;
		case _bckOff:
		rBACKWARD = '\0';
		break;
		case _ltOn:
		rLEFT = 'a';
		break;
		case _ltOff:
		rLEFT = '\0';
		break;
		case _rtOn:
		rRIGHT = 'a';
		break;
		case _rtOff:
		rRIGHT = '\0';
		break;
		default:
		break;
		}
	}




	
