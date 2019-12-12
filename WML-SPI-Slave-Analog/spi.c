/*
 * spi.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Yogi Iman
 */
#include "spi.h"
#include "analog.h"
#define DDR_SPI DDRB
#define DD_MISO DDB3

char SPI_KirimHuruf(char *huruf)
{
	while(*huruf){
		SPI_SlaveReceive(*huruf);
		huruf++;
	}
	return 0;
}

char SPI_KirimAngka(uint16_t angka)
{
	char kar[10];
	sprintf(kar, "%d", angka);
	SPI_KirimHuruf(kar);
	return 0;
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR = (1<<SPE);
}

char SPI_SlaveReceive(char dataADC)
{
	/* Wait for reception complete */
	SPDR=dataADC; // confirm to master already received
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}
