/*
* SmartHome.c
*
* Created: 12/17/2020 5:13:14 PM
*  Author: Ahmed
*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SmartHome.h"
#include "LCD.h"
#include "LED.h"
#include "std_types.h"
#include "SPI_MASTER.h"

volatile unsigned char rxdata=0;
volatile unsigned char data_recevied=0;
uint8 Pass_Login[4] = {0};
uint8 flag1 = 0;

void First_Login(void)
{
	uint8 temp1 = 0;
	uint8 Size = 0;
	uint8 temp2 = 0;
	
	temp2 = EE_Addres;
	
	temp1 = EEPROM_uRead(0x00);
	
	if (temp1 == 0xFF)
	{
		LCD_vSendString("Welcome!");
		_delay_ms(200);
		LCD_vClearDisplay();
		LCD_vSendString("Enter Password");
		LCD_vMoveCursor(1,0);
		
	while (!((rxdata == 0x0D)&&(Size == 4)))
	{
		if ((data_recevied == 1)&&(Size != 4))
		{
			data_recevied=0;
			
			LCD_vSendChar('A',rxdata);
			LCD_vSendCmd('A',0x10);
			LCD_vSendChar('A','*');
			EEPROM_vWrite(temp2,rxdata);
			Size++;
			++temp2;
		}
	}
	EEPROM_vWrite(0x00,0x03);
	}	
}	

void Second_Login(void)
{
	uint8 temp1 = 0;
	uint8 temp = 0;
	uint8 Size = 0;
	uint8 i = 0;

	temp1 = EEPROM_uRead(0x00);
	
	if (temp1 == 0x03)
	{
		LCD_vClearDisplay();
		LCD_vSendString("Welcome Sir!");
		_delay_ms(200);
		LCD_vClearDisplay();
		LCD_vSendString("Enter Password");
		LCD_vMoveCursor(1,0);
		
		data_recevied = 0;
		
		while (!((temp == 0x0D)&&(Size == 4)))
		{
			if ((data_recevied == 1)&&(Size != 4))
			{
				data_recevied=0;
				LCD_vSendChar('A',rxdata);
				LCD_vSendCmd('A',0x10);
				LCD_vSendChar('A','*');
				Pass_Login[i] = rxdata;
				++i;
				Size++;
			}
			temp = rxdata;
		}
		rxdata = 0;
		temp = 0;
	}
	
	
}

uint8 Pass_vCheck(void)
{
	uint8 temp = 0;
	uint8 Size = 0;
	uint8 i = 0;
	
	temp = EE_Addres;
	while (!(Size == 4))
	{
		if (Pass_Login[i] == EEPROM_uRead(temp))
		{
			++i;
			++temp;
			++Size;
		}
		else
		{
			LCD_vClearDisplay();
			LCD_vSendString("Wrong Password");
			LED_vTurnon('c',7);
			_delay_ms(500);
			LCD_vClearDisplay();
			LED_vTurnoff('c',7);			
			return 0;
		}
	}
	return 1;
}

void Home_vMenu(void)
{
	while (flag1 != 1)
	{
		if (Pass_vCheck() == 1)
		{
			LCD_vClearDisplay();
			LCD_vSendString("Home Rooms!");
			LCD_vMoveCursor(1,0);
			LCD_vSendString("1-R1 2-R2 3-R3");
			flag1 = 1;
		}
		else
		{
			Second_Login();
		}
	}
	flag1 = 0;
}

void Room_vNumber(void)
{
	uint8 temp1;
	uint8 temp2 = 0;
	
	while (temp2 != 1)
	{
		if(data_recevied==1)
		{
			temp1 = rxdata;
			
			if (temp1 == '1')
			{
				data_recevied=0;
				LCD_vClearDisplay();
				LCD_vSendString("ROOM 1 Light");
				LCD_vMoveCursor(1,0);
				LCD_vSendString("O-ON  F-OFF");
				SPI_MasterTransmit(temp1);
				temp2++;
			}
			else if (temp1 == '2')
			{
				data_recevied=0;
				LCD_vClearDisplay();
				_delay_ms(50);
				LCD_vSendString("ROOM 2 Light");
				LCD_vMoveCursor(1,0);
				LCD_vSendString("O-ON   F-OFF");
				SPI_MasterTransmit(temp1);
				temp2++;
			}
			else if (temp1 == '3')
			{
				data_recevied=0;
				LCD_vClearDisplay();
				LCD_vSendString("ROOM 3 Light");
				LCD_vMoveCursor(1,0);
				LCD_vSendString("O-ON  F-OFF");
				SPI_MasterTransmit(temp1);
				temp2++;
			}
		}
	}
}

void Room_vLight(void)
{
	uint8 temp3;
	uint8 temp4 = 0;
	
	while (temp4 != 1)
	{
		if (data_recevied==1)
		{
			temp3 = rxdata;
			if (temp3 == 'o')
			{
				data_recevied = 0;
				LCD_vClearDisplay();
				LCD_vSendString("Light_On");
				SPI_MasterTransmit(temp3);
				temp4++;
				_delay_ms(250);
				LCD_vClearDisplay();
			}
			else if (temp3 == 'f')
			{
				data_recevied = 0;
				LCD_vClearDisplay();
				LCD_vSendString("Light Off");
				SPI_MasterTransmit(temp3);
				temp4++;
				_delay_ms(250);
				LCD_vClearDisplay();
			}
		}
	}
}

ISR(USART_RXC_vect)
{
	data_recevied=1;
	rxdata=UDR;
	//LED_vToggle('c',7);
}