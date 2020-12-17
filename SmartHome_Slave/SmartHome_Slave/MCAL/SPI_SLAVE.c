/*
 * SPI_SLAVE.c
 *
 * Created: 11/27/2020 10:58:12 AM
 *  Author: Ahmed
 */ 

#include <avr/io.h>
#include "SPI_SLAVE.h"
#include "std_types.h"

void SPI_vInit_Slave()
{
	/*cnfg slave*/
	CLR_BIT(SPCR,MSTR);
	/*enable spi*/
	SPCR |= (1<<SPE);
	/*set ddr for miso*/
	DDRB |= (1<<MISO);
}


char SPI_u8SlaveReceive()
{
	/*chech if transmission finish*/
	while ((SPSR&(1<<SPIF)) == 0)
	{ /*wait*/}
	/*receive data*/
	return SPDR;
}