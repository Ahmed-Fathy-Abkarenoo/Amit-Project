/*
* LED.c
*
* Created: 10/29/2020 3:32:03 PM
*  Author: Ahmed
*/

#include "LED.h"

void LED_vInit(uint8 portname, uint8 pinnumber)
{
	DIO_vSetPinDir(portname ,pinnumber ,1 );
}

void LED_vTurnon(uint8 portname, uint8 pinnumber)
{
	DIO_vWritepin(portname, pinnumber, 1);
}

void LED_vTurnoff(uint8 portname, uint8 pinnumber)
{
	DIO_vWritepin(portname, pinnumber, 0);
}

void LED_vToggle(uint8 portname, uint8 pinnumber)
{
	DIO_vTogglepin(portname, pinnumber);
}