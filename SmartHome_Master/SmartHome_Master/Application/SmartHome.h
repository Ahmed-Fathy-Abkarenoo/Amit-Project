/*
 * SmartHome.h
 *
 * Created: 12/16/2020 12:16:25 PM
 *  Author: Ahmed
 */ 


#ifndef SMARTHOME_H_
#define SMARTHOME_H_

#include "std_types.h"

#define  EE_Addres  0x01

void First_Login(void);

void Second_Login(void);

uint8 Pass_vCheck(void);

void Home_vMenu(void);

void Room_vNumber(void);

void Room_vLight(void);

#endif /* SMARTHOME_H_ */