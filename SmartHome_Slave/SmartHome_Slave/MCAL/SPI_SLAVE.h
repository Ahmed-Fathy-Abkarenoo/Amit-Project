/*
 * SPI_SLAVE.h
 *
 * Created: 11/27/2020 11:02:02 AM
 *  Author: Ahmed
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

#define MISO 6
#define SS 4

void SPI_vInit_Slave();

char SPI_u8SlaveReceive();

#endif /* SPI_SLAVE_H_ */