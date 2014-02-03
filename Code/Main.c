/*
*	SMOOTH REMOTE CONTROLLED BOT
*
*	Use: 4 - buttons
*	Forward, Backward, Left, Right
*
*	Req.:
*	External header file "remote.h"
*	for recieving commands: forward, backward, left, right
*
*	Copyright(C) 2011, SmoothRC
*	Subhajit Sahu, LowVolt Group
*
*/


#include	<avr/io.h>
#include	<util/delay.h>
#include	<math.h>
// External header file for recieving remote commands
#include	"remote.h"
#include	"wheels.h"


//Function declarations
int main(void);
void UpdateBotSpeed(void);



//Constants
#define				_vBotMax		100
#define				_vBotMin		-100
#define				_tBotMax		100
#define				_tBotMin		-100
#define				_vBotDamp		0.5
#define				_tBotDamp		0.5
#define				_fwdP			1
#define				_fwdI			1
#define				_bckP			1
#define				_bckI			1
#define				_ltP			1
#define				_ltI			1
#define				_rtP			1
#define				_rtI			1



//Global Variables
extern	rFORWARD, rBACKWARD, fLEFT, rRIGHT;
extern	wLEFT, wRIGHT;
int		vBot, tBot;



int main()
	{
	while(1)
		{
		GetRemoteStatus();
		UpdateBotSpeed();
		DriveWheels();
		}
	}





void	UpdateBotSpeed()
	{
		if(rFORWARD && !rBACKWARD) vBot += _fwdP + _fwdI*abs(vBot);
		else if(rBACKWARD && !rFORWARD) vBot -= _bckP + _bckI*abs(vBot);
		else	vBot *= _vBotDamp;
		if(vBot > _vBotMax) vBot = _vBotMax;
		else if(vBot < _vBotMin) vBot = _vBotMin;
		if(rLEFT && !rRIGHT) tBot += _ltP + _ltI*abs(tBot);
		else if(rRIGHT && !rLEFT) tBot -= _rtP + _rtI*abs(tBot);
		else	tBot *= _tBotDamp;
		if(tBot > _tBotMax) tBot = _tBotMax;
		else if(tBot < _tBotMin) tBot = _tBotMin;
		wLEFT = vBot * (_tBotMax - (((tBot>0)?tBot:0)*2));
		wRIGHT = vBot * (_tBotMax + (((tBot<0)?tBot:0)*2));
	}


