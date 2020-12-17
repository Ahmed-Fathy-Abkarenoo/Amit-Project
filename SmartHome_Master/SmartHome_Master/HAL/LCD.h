/*
 * LCD.h
 *
 * Created: 11/6/2020 9:45:04 PM
 *  Author: Ahmed
 */ 


#include "std_types.h"

#ifndef LCD_H_
#define LCD_H_

//#define SET_BIT(REGISTER,BIT_NUM) (REGISTER = REGISTER | (1<<BIT_NUM))
//#define CLR_BIT(REG,BIT_NUM)   (REG = REG &(~(1<<BIT_NUM)))
//#define TOGGLE_BIT(REG,BIT_NUM)   (REG = REG ^ (1<<BIT_NUM))
//#define IS_BIT_SET(REG,BIT_NUM) ((REG &(1<<BIT_NUM))>>BIT_NUM)

#define RS         PINB1    /*Register Select*/
#define RW         PINB2    /*Read-Write*/
#define EN         PINB3 
#define PORT_NAME  PORTA   


void LCD_vInit();

void LCD_vSendCmd(uint8 portname, uint8 Cmd);

void LCD_vSendChar(uint8 PoNa, uint8 Data);

void LCD_vSendString(uint8 *str);

void LCD_vMoveCursor(uint8 row, uint8 col);

void LCD_vClearDisplay();

void LCD_vNewLine();


#endif /* LCD_H_ */