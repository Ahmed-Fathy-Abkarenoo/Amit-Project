/*
 * Timer.c
 *
 * Created: 11/20/2020 8:58:37 AM
 *  Author: Ahmed
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_types.h"
#include "Timer.h"


void Timer0_vInit(void)
{
	/*choose ctc mode*/
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	
	/*select ocr0*/
	OCR0 = 152;
	
	/*enable global i-bit*/
	sei();
	
	/*enable ocieo from timsk register*/
	SET_BIT(TIMSK,OCIE0);
	
	/*choose prescaler 1024*/
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
}

void PWM_vInit(void)
{
	/*select phase correct pwm*/
	SET_BIT(TCCR1A,WGM10);
	
	/*chosse noninverting mode*/
	SET_BIT(TCCR1A,COM1B1);
	
	/*chosse ocr0*/
	OCR1BL=0xff;
	
	/*set pin to output*/
	DIO_vSetPinDir('d',4,1);
	
	/*chosse prescaler /1042*/
	TCCR1B |= (1<<CS10)|(1<<CS12);
}

void PWM_Setduty(uint8 percentage)
{
	OCR1BL = (char)((percentage/100.0)*255);
}