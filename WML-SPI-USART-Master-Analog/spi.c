/*
 * spi.c
 *
 *  Created on: Oct 18, 2019
 *      Author: asus
 */
#include <avr/io.h>
#include "uart.h"
#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2

void SPI_MasterInit(void) {
	/* Set MOSI and SCK output, all others input */
	DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}
char SPI_MasterTransmit(char cData) {
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while (!(SPSR & (1 << SPIF)));
	return SPDR;
}
