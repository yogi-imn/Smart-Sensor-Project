/*
 * main.c
 *
 *  Created on: Oct 3, 2019
 *      Author: Yogi Iman
 */

#include <avr/io.h>
#include <util/delay.h>
#include "analog.h"
#include "spi.h"
#include "uart.h"
#include <stdio.h>
#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3
uint8_t channel=0;
uint8_t UWU = 0x82;
int data;

int main( void) {
	ADCInit();
	DDRA=0xFF; //port A as output
	PORTA=0xFF; //reset all port A
	SPI_SlaveInit();
	USARTInit();
	while (1) {
			//SPI	 = A/RH A/RL D/R CAL S-3 S-2 S-1 DEC
			//			7	 6	  5	  4	  3	  2	  1	  0

			//UART :
			//ARAW	= 7;	DRAW	= 6;	D  	= 5;	CS3	= 4
			//CS2 	= 3;	CS1 	= 2;	CSA	= 1

		switch(UWU){
		//switch(SPDR){
		  //case 0b76543210
		  //case 0b10000010 : channel=1; break;
			case 0b10000010 : //HEX=0x82
							  USARTPutNum(DataADCH(0)); USARTPutStr("\n\r"); break;
			case 0b10000100 : //HEX=0x84
							  USARTPutNum(DataADCH(1)); USARTPutStr("\n\r"); break;
			case 0b10001000 : //HEX=0x88
							  USARTPutNum(DataADCH(2)); USARTPutStr("\n\r"); break;
			case 0b01000010 : //HEX=0x42
							  USARTPutNum(DataADCL(0)); USARTPutStr("\n\r"); break;
			case 0b01000100 : //HEX=0x44
							  USARTPutNum(DataADCL(1)); USARTPutStr("\n\r"); break;
			case 0b01001000 : //HEX=0x48
							  USARTPutNum(DataADCL(2)); USARTPutStr("\n\r"); break;
			case 0b00100000 : //HEX=0x20
							  USARTPutNum(DigitalRAW(0));USARTPutNum(DigitalRAW(1));
							  USARTPutNum(DigitalRAW(2));USARTPutStr("\n\r"); break;
		}
		//sprintf(str, "adc_read = %d \r",dataADC);
				//PORTA=~SPI_SlaveReceive(0x0F);
	}
}
