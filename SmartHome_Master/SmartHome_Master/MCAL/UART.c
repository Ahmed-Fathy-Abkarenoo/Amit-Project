/*
 * UART.c
 *
 * Created: 11/21/2020 10:38:37 AM
 *  Author: Ahmed
 */ 

#define CPU_FREQ 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_types.h"
#include "DIO.h"
#include "UART.h"

void UART_vInit(unsigned long baud)
{
	unsigned short ubrr;
		
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	ubrr =  ( (CPU_FREQ/ (16*baud)) - 1);
		
	UBRRL = (char) ubrr;
	UBRRH = (char) (ubrr >> 8);
	
	/*3 - Choose number of data bits to be sent from UCSRC We will work with 8 bits.*/
	UCSRC = (1<<URSEL)|(1<<UCSZ0) | (1<<UCSZ1);

	UCSRB = (1<<RXCIE);
	
	/*2 - Enable UART Sender & Receiver*/
	UCSRB |= (1<<TXEN) | (1<<RXEN);
}

void UART_vSend(unsigned char val)
{
	/*Wait for Transmit buffer to be empty*/
	while( (UCSRA & (1<<UDRE)) == 0 )
	{/*wait*/}
	
	/*Put data to transmit buffer*/
	UDR = val;
}




#if 0
void UART_vInit(unsigned long baud)
{
	UCSRC=0;
	UCSRB=0;
	/* set baud rate in ubrrl/ubrrh*/
	unsigned short temp= ((F_CPU/(16*baud))-1);
	UBRRL = (unsigned char) temp;
	UBRRH = (unsigned char) (temp>>8);
	
	/* chosse frame 8 bit\1 stop bit/ no parity*/
	UCSRC |= (1<<URSEL);
	/* no parity*/
	//CLR_BIT(UCSRC,UPM0);
	//CLR_BIT(UCSRC,UPM1);
	/* 1 stop bit*/
	//CLR_BIT(UCSRC,USBS);
	/* 8 bit frame*/
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	//CLR_BIT(UCSRB,UCSZ2);
	
	/* enable interrupt reception*/
	//SET_BIT(UCSRB,RXCIE);
	UCSRB = (1<<RXCIE);
	
	/* enable globale i-bit*/
	sei();
	
	/* enable uart tx/rx*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void UART_vSend(unsigned char data)
{
	while(IS_BIT_SET(UCSRA,UDRE))
	{
		/* wait*/
	}
	UDR = data;
}

#endif