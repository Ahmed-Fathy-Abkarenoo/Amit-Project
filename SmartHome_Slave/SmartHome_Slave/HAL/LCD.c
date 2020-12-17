/*
 * LCD.c
 *
 * Created: 11/6/2020 10:17:39 PM
 *  Author: Ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
#include <avr/io.h>
#include "LCD_cfg.h"


static void send_falling_edge(void);

uint8 counter = 0;
uint8 Line_NO=0;

#ifdef  LCD_8_BIT

void LCD_vInit()
{
	DIO_vSetPortDir('b',0x0ff);         /*EN/RS/RW*/
	DIO_vSetPortDir('a',0x0E);
	
	DIO_vWritepin('b',RW,0);
	
	LCD_vSendCmd('a', 0x038);         /*Initialization*/
	LCD_vSendCmd('a', 0x01);          /*clear screen*/
	LCD_vSendCmd('a', 0x0F);          /*blink cursor*/
	
	_delay_ms(20);
}

void LCD_vSendCmd(uint8 portname, uint8 Cmd)
{
	DIO_vWriteport(portname,Cmd);        /*put data on data lines*/
	DIO_vWritepin('b',RS,0);             /*choose RS=0*/
	send_falling_edge();                 /*send falling edge*/
}

void LCD_vSendChar(uint8 PoNa, uint8 Data)
{
	DIO_vWriteport(PoNa,Data);           /*put data on data lines*/
	DIO_vWritepin('b',RS,1);             /*choose RS=0*/
	send_falling_edge();                 /*send falling edge*/
}

#else             /*LCD_4_BIT*/
void LCD_vInit(void)
{
	DIO_vSetPortDir('b',0x0E);         /*EN/RS/RW*/
	DIO_vSetPortDir('a',0xf0);
	
	DIO_vWritepin('b',RW,0);
	
	LCD_vSendCmd('a', 0x033);         /*Initialization*/
	LCD_vSendCmd('a', 0x032);
	LCD_vSendCmd('a', 0x028);
	LCD_vSendCmd('a', 0x01);          /*clear screen*/
	LCD_vSendCmd('a', 0x0F);          /*blink cursor*/
	
	_delay_ms(20);
}

void LCD_vSendCmd(uint8 portname, uint8 Cmd)
{
	PORT_NAME&=0x0f;
	PORT_NAME |= (Cmd&0xf0);           /*put data on data lines*/
	DIO_vWritepin('b',RS,0);       /*choose RS=0*/
	send_falling_edge();           /*send falling edge*/
	
	PORT_NAME&=0x0f;
	PORT_NAME|=(Cmd<<4);
	DIO_vWritepin('b',RS,0); 
	send_falling_edge();
}

void LCD_vSendChar(uint8 PoNa, uint8 Data)
{
	PORT_NAME&=0x0f;
	PORT_NAME |= (Data&0xf0);          /*put data on data lines*/
	DIO_vWritepin('b',RS,1);          /*choose RS=0*/
	send_falling_edge();           /*send falling edge*/
	
	PORT_NAME&=0x0f;
	PORT_NAME|=(Data<<4);
	DIO_vWritepin('b',RS,1); 
	send_falling_edge();
	
	LCD_vNewLine();
}
#endif

void LCD_vSendString(uint8 *str)
{
	while(*str)
{LCD_vSendChar('a',*str++);}
}

void LCD_vMoveCursor(uint8 row, uint8 col)
{
	uint8 temp;
	if(row==0)
{temp=0x80+col;}    /*0x80-0x8f*/
	else
{temp=0xc0+col;}    /*0xc0-0xcf*/
	LCD_vSendCmd('a',temp);
}

static void send_falling_edge(void)
{
	DIO_vWritepin('b',EN,1);
	_delay_ms(5);
	DIO_vWritepin('b',EN,0);
	_delay_ms(5);
}

void LCD_vClearDisplay()
{
	LCD_vSendCmd('a', 0x01);          /*clear screen*/
	LCD_vSendCmd('a', 0x0F);          /*blink cursor*/
	_delay_ms(20);
}

void LCD_vNewLine()
{
	counter++;
	
	if (counter == 16)
	{
		if (Line_NO == 1)
		{
			_delay_ms(100);
			LCD_vClearDisplay();
			Line_NO = 0;
		}
		else
		{
			LCD_vMoveCursor(1,0);
			counter = 0;
			Line_NO++;
		}
	}

}
