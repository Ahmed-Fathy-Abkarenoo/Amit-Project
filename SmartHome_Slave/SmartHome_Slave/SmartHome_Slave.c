/*
 * SmartHome_Slave.c
 *
 * Created: 12/13/2020 11:48:18 AM
 *  Author: Ahmed
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_types.h"
#include "DIO.h"
#include "SPI_SLAVE.h"

int main(void)
{
	SPI_vInit_Slave();
	LED_vInit('A',0);
	LED_vInit('A',1);
	LED_vInit('A',2);
	uint8 temp;
    while(1)
    {
		 temp = SPI_u8SlaveReceive();
		if (temp == '1')
		{
			temp = SPI_u8SlaveReceive();
			
			if (temp == 'o')
			{
				LED_vTurnon('A',0);
			}
			else if (temp == 'f')
			{
				LED_vTurnoff('A',0);
			}
		}
		else if (temp == '2')
		{
			temp = SPI_u8SlaveReceive();
				if (temp == 'o')
				{
					LED_vTurnon('A',1);
				}
				else if (temp == 'f')
				{
					LED_vTurnoff('A',1);
				}
		}
		else if (temp == '3')
		{
			temp = SPI_u8SlaveReceive();
			if (temp == 'o')
			{
				LED_vTurnon('A',2);
			}
			else if (temp == 'f')
			{
				LED_vTurnoff('A',2);
			}
		}
		
    }
}