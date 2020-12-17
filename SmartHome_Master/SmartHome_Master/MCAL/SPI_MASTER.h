/*
 * SPI_MASTER.h
 *
 * Created: 11/27/2020 10:11:59 AM
 *  Author: Ahmed
 */ 


#ifndef SPI_MASTER_H_
#define SPI_MASTER_H_

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

void SPI_vInit_Master();

void SPI_MasterTransmit(char data);


#endif /* SPI_MASTER_H_ */