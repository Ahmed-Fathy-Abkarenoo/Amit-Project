/*
* DIO.c
*
* Created: 10/24/2020 11:18:35 AM
*  Author: Ahmed
*/

#include "std_types.h"
#include "DIO.h"
#include <avr/io.h>

void DIO_vSetPinDir(uint8 portName, uint8 pinNum, uint8 dir)
{
	switch(portName)
	{
		case'a':
		case'A':
		if(1==dir)
	{DDRA |=(1<<pinNum);}
		else
	{DDRA &=~(1<<pinNum);}
		break;
		
		case'b':
		case'B':
		if(1==dir)
	{DDRB |=(1<<pinNum);}
		else
	{DDRB &=~(1<<pinNum);}
		break;
		
		case'c':
		case'C':
		if(1==dir)
	{DDRC |=(1<<pinNum);}
		else
	{DDRC &=~(1<<pinNum);}
		break;
		
		case'd':
		case'D':
		if(1==dir)
	{DDRD |=(1<<pinNum);}
		else
	{DDRD &=~(1<<pinNum);}
		break;
	}
	
}

void DIO_vWritepin(uint8 portName, uint8 pinNum, uint8 pinvalue)
{
	switch(portName)
	{
		case'a':
		case'A':
		if(1==pinvalue)
	{PORTA |=(1<<pinNum);}
		else
	{PORTA &=~(1<<pinNum);}
		break;
		
		case'b':
		case'B':
		if(1==pinvalue)
	{PORTB |=(1<<pinNum);}
		else
	{PORTB &=~(1<<pinNum);}
		break;
		
		case'c':
		case'C':
		if(1==pinvalue)
	{PORTC |=(1<<pinNum);}
		else
	{PORTC &=~(1<<pinNum);}
		break;
		
		case'd':
		case'D':
		if(1==pinvalue)
	{PORTD |=(1<<pinNum);}
		else
	{PORTD &=~(1<<pinNum);}
		break;
	}
}

uint8 DIO_u8Readpin(uint8 portName, uint8 pinNum)
{
	char temp = 0;
	
	switch(portName)
	{
		case'a':
		case'A':
		temp = (PINA&(1<<pinNum))>>pinNum;
		break;
		
		case'b':
		case'B':
		temp = (PINB&(1<<pinNum))>>pinNum;
		break;
		
		case'c':
		case'C':
		temp = (PINC&(1<<pinNum))>>pinNum;
		break;
		
		case'd':
		case'D':
		temp = (PIND&(1<<pinNum))>>pinNum;
		break;
	}
	return temp;
}

void DIO_vTogglepin(uint8 portname, uint8 pinNum)
{
	switch(portname)
	{
		case'a':
		case'A':
	PORTA ^=(1<<pinNum);
		break;
		
		case'b':
		case'B':
	PORTB ^=(1<<pinNum);
		break;
		
		case'c':
		case'C':
	PORTC ^=(1<<pinNum);
		break;
		
		case'd':
		case'D':
	PORTD ^=(1<<pinNum);
		break;
	}
}

void DIO_vSetPortDir(uint8 portNam, uint8 portVal)
{
	
	switch(portNam)
	{
		case'a':
		case'A':
		DDRA |= portVal;
		break;
		
		case'b':
		case'B':
		DDRB |= portVal;
		break;
		
		case'c':
		case'C':
		DDRC |= portVal;
		break;
		
		case'd':
		case'D':
		DDRD |= portVal;
		break;
	}
}

void DIO_vWriteport(uint8 portnam, uint8 portval)
{
		switch(portnam)
		{
			case'a':
			case'A':
			PORTA |= portval;
			break;
			
			case'b':
			case'B':
			PORTB |= portval;
			break;
			
			case'c':
			case'C':
			PORTC |= portval;
			break;
			
			case'd':
			case'D':
			PORTD |= portval;
			break;
		}
}