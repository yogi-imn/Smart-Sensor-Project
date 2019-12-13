/*
 * spi.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Yogi Iman
 */

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <stdio.h>

#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3

//SPI Slave
void SPI_SlaveInit(void);
char SPI_SlaveReceive(char cData);
char SPI_SlavePrint(char *text);
char SPI_SlavePrintNum(uint16_t number);

#endif /* SPI_H_ */
