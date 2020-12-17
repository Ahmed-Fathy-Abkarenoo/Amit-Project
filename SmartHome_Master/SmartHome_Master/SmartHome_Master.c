/*
* SmartHome_Master.c
*
* Created: 12/4/2020 7:46:00 PM
*  Author: Ahmed
*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_types.h"
#include "DIO.h"
#include "UART.h"
#include "Bluetooth.h"
#include "SPI_MASTER.h"
#include "EEPROM.h"
#include "LED.h"
#include "BUZZER.h"
#include "LCD.h"
#include "SmartHome.h"


int main(void)
{
	SPI_vInit_Master();
	LCD_vInit();
	HC05_vInit();
	LED_vInit('C',7);
	sei();
	
   First_Login();
   Second_Login();
   
	while(1)
	{
		Home_vMenu();
		Room_vNumber();
		Room_vLight();
	}
}

