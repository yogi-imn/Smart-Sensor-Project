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

unsigned char Result='0';
unsigned char Request='0';
uint8_t channel=0;
uint8_t UWU = 0x82;
//uint8_t dH[3]={0,0,0},dL[3]={0,0,0};
uint8_t dH0=0,dH1=0,dH2=0;
uint8_t dL0=0,dL1=0,dL2=0;
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

//	Request=SPI_SlaveReceive(Result);

		switch(UWU){
		  //case 0b76543210
			case 0b10000010 : //HEX=0x82
							  {ReadADC(0, 0, &dH0, 0);
							  USARTPutNum(dH0); USARTPutStr("\n\r");} break;
//							  USARTPutNum(ADCHigh(0)); USARTPutStr("\n\r"); break;
			case 0b10000100 : //HEX=0x84
							  ReadADC(1, 0, &dH1, 0);
							  USARTPutNum(dH1); USARTPutStr("\n\r"); break;
//							  USARTPutNum(ADCHigh(1)); USARTPutStr("\n\r"); break;
			case 0b10001000 : //HEX=0x88
						   	  ReadADC(2, 0, &dH2, 0);
							  USARTPutNum(dH2); USARTPutStr("\n\r"); break;
//							  USARTPutNum(ADCHigh(2)); USARTPutStr("\n\r"); break;
			case 0b01000010 : //HEX=0x42
							  ReadADC(0, &dL0, 0, 0);
							  USARTPutNum(dL0); USARTPutStr("\n\r"); break;
//							  USARTPutNum(ADCLow(0)); USARTPutStr("\n\r"); break;
			case 0b01000100 : //HEX=0x44
							  ReadADC(1, &dL1, 0, 0);
							  USARTPutNum(dL1); USARTPutStr("\n\r"); break;
//							  USARTPutNum(ADCLow(1)); USARTPutStr("\n\r"); break;
			case 0b01001000 : //HEX=0x48
							  ReadADC(2, &dL2, 0, 0);
							  USARTPutNum(dL2); USARTPutStr("\n\r"); break;
//							  USARTPutNum(ADCLow(2)); USARTPutStr("\n\r"); break;
			case 0b00100000 : //HEX=0x20
							  CalibratingSensor(0);
							  CalibratingSensor(1);
							  CalibratingSensor(2);
							  USARTPutNum(DigitalRAW(0));USARTPutNum(DigitalRAW(1));
							  USARTPutNum(DigitalRAW(2));USARTPutStr("\n\r"); break;
		}
	}
}
