/*
 * DIO.h
 *
 * Created: 10/24/2020 11:17:39 AM
 *  Author: Ahmed
 */ 

#include "std_types.h"

#ifndef DIO_H_
#define DIO_H_

void DIO_vSetPinDir(uint8 portName, uint8 pinNum, uint8 dir);

void DIO_vWritepin(uint8 portname, uint8 pinNum, uint8 pinvalue);

uint8 DIO_u8Readpin(uint8 portName, uint8 pinNum);

void DIO_vTogglepin(uint8 portname, uint8 pinNum);

void DIO_vSetPortDir(uint8 portNam, uint8 portVal);

void DIO_vWriteport(uint8 portnam, uint8 portval);



#endif /* DIO_H_ */