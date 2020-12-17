/*
 * LED.h
 *
 * Created: 10/29/2020 3:31:43 PM
 *  Author: Ahmed
 */ 

#include "std_types.h"

#ifndef LED_H_
#define LED_H_

void LED_vInit(uint8 portname, uint8 pinnumber);

void LED_vTurnon(uint8 portname, uint8 pinnumber);

void LED_vTurnoff(uint8 portname, uint8 pinnumber);

void LED_vToggle(uint8 portname, uint8 pinnumber);



#endif /* LED_H_ */