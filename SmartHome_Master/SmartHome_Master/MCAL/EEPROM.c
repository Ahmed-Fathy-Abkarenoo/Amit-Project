/*
 * EEPROM.c
 *
 * Created: 11/6/2020 1:12:10 PM
 *  Author: Ahmed
 */ 

#include "std_types.h"
#include <avr/io.h>
#include "EEPROM.h"

void EEPROM_vWrite(uint16 address, uint8 val)
{	
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	
	/* Set up address and data registers */
	//EEAR = address;
	EEARH = (char) (address>>8);
	EEARL = (char) address;
	
	EEDR = val;
	
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

uint8 EEPROM_uRead(unsigned int uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}