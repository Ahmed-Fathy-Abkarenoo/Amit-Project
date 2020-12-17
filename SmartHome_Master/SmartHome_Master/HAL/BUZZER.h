/*
 * BUZZER.h
 *
 * Created: 11/4/2020 8:57:58 AM
 *  Author: Ahmed
 */ 

#ifndef BUZZER_H_
#define BUZZER_H_

#define poNam 'A'
#define pinNu 3

#define BUZZER_vInit(port,pin)      DIO_vSetPinDir(port,pin,1);


#define BUZZER_vTurnon(port,pin)    DIO_vWritepin(port,pin,1);


#define BUZZER_vTurnoff(port,pin)   DIO_vWritepin(port,pin,0);


#define BUZZER_vToggle(port,pin)    DIO_vTogglepin(port,pin);


#endif /* BUZZER_H_ */