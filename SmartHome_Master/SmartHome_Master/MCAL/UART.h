/*
 * UART.h
 *
 * Created: 11/21/2020 10:38:22 AM
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

void UART_vInit(unsigned long baud);
void UART_vSend(unsigned char val);

//void UART_vInit(unsigned long baud);

//void UART_vSend(unsigned char data);

#endif /* UART_H_ */