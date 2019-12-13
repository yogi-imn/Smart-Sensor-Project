/*
 * main.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Yogi Iman
 */
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "spi.h"

int data[8];
uint8_t DataDRAW;
uint8_t dH0=0,dH1=0,dH2=0;
uint8_t dL0=0,dL1=0,dL2=0;
uint16_t dTen0=0,dTen1=0,dTen2=0;

void DigitalRAW(void);
void AnalogRAW(void);
void AnalogRAWS1(void);
void AnalogRAWS2(void);
void AnalogRAWS3(void);

int main(void) {
	USARTInit();
	SPI_MasterInit();
	DDRA=0xFF;
	while (1) {
		DigitalRAW();
		AnalogRAW();
		AnalogRAWS1();
		USARTPutStr("\n");
		AnalogRAWS2();
		USARTPutStr("\n");
		AnalogRAWS3();
		USARTPutStr("\n");
	}
}

void DigitalRAW(void){
		USARTPutStr("digitalRaw: ");
		DataDRAW = SPI_MasterTransmit(0x20);
		_delay_us(500);
		USARTPutNum(DataDRAW);
		USARTPutStr("\n");
}

void AnalogRAW(void){
	USARTPutStr("digitalRaw: ");
	AnalogRAWS1();
	USARTPutStr("[]");
	AnalogRAWS2();
	USARTPutStr("[]");
	AnalogRAWS3();
	USARTPutStr("\n");
}
void AnalogRAWS1(void){
	USARTPutStr("analogRawS1: ");
	dH0 = SPI_MasterTransmit(0x82);
	_delay_us(500);
	dL0 = SPI_MasterTransmit(0x42);
	_delay_us(500);
	dTen0 = (dH0<<8)|dL0;

	USARTPutNum(dH0);
	USARTPutStr("-");
	USARTPutNum(dL0);
	USARTPutStr("-");
	USARTPutNum(dTen0);
}
void AnalogRAWS2(void){
	USARTPutStr("analogRawS2: ");
	dH1 = SPI_MasterTransmit(0x84);
	_delay_us(500);
	dL1 = SPI_MasterTransmit(0x44);
	_delay_us(500);
	dTen1 = (dH1<<8)|dL1;

	USARTPutNum(dH1);
	USARTPutStr("-");
	USARTPutNum(dL1);
	USARTPutStr("-");
	USARTPutNum(dTen1);
}
void AnalogRAWS3(void){
	USARTPutStr("analogRawS3: ");
	dH2 = SPI_MasterTransmit(0x88);
	_delay_us(500);
	dL2 = SPI_MasterTransmit(0x48);
	_delay_us(500);
	dTen2 = (dH2<<8)|dL2;

	USARTPutNum(dH2);
	USARTPutStr("-");
	USARTPutNum(dL2);
	USARTPutStr("-");
	USARTPutNum(dTen2);
}
