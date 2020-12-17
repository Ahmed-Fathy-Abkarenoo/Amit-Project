/*
 * Bluetooth.c
 *
 * Created: 11/21/2020 12:42:33 PM
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

void HC05_vInit(void)
{
	UART_vInit(9600);
}

void HC05_vSend(unsigned char data)
{
	UART_vSend(data);
}

void HC05_vprint(unsigned char *str)
{
	uint8 *ptr = str;
	while (*ptr)
	{
		HC05_vSend(*ptr++);
	}
}