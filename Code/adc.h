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
#include	<avr/interrupt.h>
#include	<util/delay.h>
#include	<math.h>
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


void Start_ADC()
	{
	ADMUX = 0b11100000;			// Select channel for AD conversion
	ADCSRA = 0b11000011;		// Start conversion & sampling rate = AVR_FREQ/8
	while(!(ADCSRA & 0b10000));	// Wait till conversion completes
	ADCSRA |= 0b10000;			// Clear AD interrupt flag
	return(ADCH);				// AD value
	}




ISR(TIMER)_COMP_vect)
	{
	TCNT0 = 0;					// Reload Timer Counter
	TIFR = 0b10;				// Clear timer overflow bit, timer interrupt handled
	time_now++;
	}

