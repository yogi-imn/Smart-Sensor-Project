/*
 * analog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Yogi Iman
 */

#include "analog.h"
#include <avr/io.h>
#include <util/delay.h>
uint8_t channel,DataL,DataH;
uint8_t DRAW[3];
uint8_t i;
uint8_t threshold;

void ADCInit(void)
{
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1); //setting prescaller
	ADMUX &=~(1<<ADLAR); //configure 8 bit data from ADCH
	ADMUX |=(1<<REFS0)|channel; //get ref from VCC & activate channel 0
	ADCSRA|=(1<<ADEN);	//enable ADC
}
uint16_t ReadADC(uint8_t channel)
{
	ADMUX &= ~(0x1F); //reset bit 0-4 ADMUX
	ADMUX |= channel; //mengakses data dari channel analog yang dipilih
	ADCSRA|= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);

	DataL = ADCL;
	DataH = ADCH;
	dataADC = ADCH*256 + ADCL;
	return dataADC;
}

uint16_t DataADCL(uint8_t channel){
	ReadADC(channel);
	return ADCL;
	//return ADCL;
}

uint16_t DataADCH(uint8_t channel){
	ReadADC(channel);
	return ADCH;
}

uint16_t DigitalRAW(uint8_t channel){
	ReadADC(channel);
	i=channel;
	if (dataADC < threshold){
		DRAW[i] = 0;
	}
	else{
		DRAW[i] = 1;
	}
	return DRAW[i];
}
