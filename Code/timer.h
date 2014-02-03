/*
*	SMOOTH REMOTE CONTROLLED BOT TIMER
*
*
*	Copyright(C) 2011, SmoothRC
*	Subhajit Sahu, LowVolt Group
*
*/


#include	<avr/io.h>
#include	<avr/interrupt.h>
#include	<util/delay.h>
#include	<stdint.h>
#include	<stdio.h>


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



volatile unsigned int time_now=0;
float kp,b,uk_1,ek_1,ek,sk,yk,wk,T,Ti;
unsigned int uk;

void Start_Timer()
	{
	TCCR = 0b00001011;			// CTC mode, AVR_FREQ/64
	OCR0 = 155;					// End at 155
	TCNT0 = 0;					// Start from 0
	asm("SEI");					// ~ STI
	TIMSK = 1<<OCIE0;			// Output Compare Interrupt enable
	}





ISR(TIMER_COMP_vect)
	{
	TCNT0 = 0;					// Reload Timer Counter
	TIFR = 0b10;				// Clear timer overflow bit, timer interrupt handled
	time_now++;
	}

