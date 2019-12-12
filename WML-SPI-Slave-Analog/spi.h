/*
 * spi.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Yogi Iman
 */

#ifndef SPI_H_
#define SPI_H_

#include<avr/io.h>
#include<stdio.h>
void SPI_SlaveInit(void);
char SPI_SlaveReceive(char data);
char SPI_KirimHuruf(char *huruf);
char SPI_KirimAngka(uint16_t angka);

#endif /* SPI_H_ */
