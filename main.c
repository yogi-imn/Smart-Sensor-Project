/*
 * main.c
 *
 *  Created on: Nov 8, 2019
 *      Author: Yogi Iman
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <avr/io.h>
#include <util/delay.h>
//#include "uart.h"
//#include "spi.h"

#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3
int data[8];

int main(void) {
	//USARTInit();
	//USARTBanner();
	//SPI_MasterInit();
	DDRA=0xFF;
	while (1) {
		//PORTA=SPI_MasterTransmit(0xAA);
		//USARTPutChar(USARTGetChar());
		}
}
