/*
 * EEPROM.h
 *
 * Created: 11/6/2020 1:18:05 PM
 *  Author: Ahmed
 */ 

#include "std_types.h"

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_vWrite(uint16 address, uint8 val);

unsigned char EEPROM_read(unsigned int uiAddress);



#endif /* EEPROM_H_ */