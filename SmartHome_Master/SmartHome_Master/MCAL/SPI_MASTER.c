/*
 * SPI_MASTER.c
 *
 * Created: 11/27/2020 10:11:39 AM
 *  Author: Ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_types.h"
#include "DIO.h"
#include "SPI_MASTER.h"

void SPI_vInit_Master()
{
	/*configure master or slave*/
	SPCR = (1<<MSTR);	
	/*configure clock speed /128*/
	SPCR |= (1<<SPR0);
	SPCR |= (1<<SPR1);
	CLR_BIT(SPSR,SPI2X);
	/*configure (ddr mosi/ss/sck)(op)*/
	DDRB |= (1<<MOSI);
	DDRB |= (1<<SS);
	DDRB |= (1<<SCK);
	/*put ss pin to high*/
	PORTB |= (1<<SS);
	/*enable spi peripheral*/ 
	SPCR |= (1<<SPE);
}

void SPI_MasterTransmit(char data)
{
	/*enable ss=0*/
	CLR_BIT(PORTB,SS);
	/*put data to spdr*/
	SPDR = data;
	/*check transmission is done*/
	while(IS_BIT_SET(SPSR,SPIF) == 0)
	{
		/*wait*/
	}
	/*close slave select ss=1*/
	SET_BIT(PORTB,SS);
}