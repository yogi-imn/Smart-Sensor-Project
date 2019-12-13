/*
 * spi.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Yogi Iman
 */
#include <avr/io.h>
#include "spi.h"
#include "analog.h"

char SPI_SlavePrint(char *text){
	while(*text){
		SPI_SlaveReceive(*text++);
	}
	return 0;
}

char SPI_SlavePrintNum(uint16_t number){
	char buff[100];
	sprintf(buff, "%d", number);
	SPI_SlavePrint(buff);
	return SPDR;
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	//PORTB |= (1<<PB2);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
char SPI_SlaveReceive(char cData)
{
	/* Wait for reception complete */
	//
	SPDR= cData; // confirm to master already received
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}

