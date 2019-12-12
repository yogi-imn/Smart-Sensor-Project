/*
 * analog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Yogi Iman
 */

#include "analog.h"
#include <avr/io.h>
#include <util/delay.h>
uint8_t channel,Lower,Higher;
uint8_t DRAW[3];
uint8_t i;
uint16_t ADCMax[3]={0,0,0},ADCMin[3]={1023,1023,1023};
//uint16_t ADCMax1=0,ADCMax2=0,ADCMax3=0;
//uint16_t ADCMin1=1023,ADCMin2=1023,ADCMin3=1023;
uint16_t dataADC[3],threshold[3],sepuluhbit[3];

void ADCInit(void)
{
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1); //setting prescaller
	ADMUX &=~(1<<ADLAR); //configure 8 bit data from ADCH
	ADMUX |=(1<<REFS0)|channel; //get ref from VCC & activate channel 0
	ADCSRA|=(1<<ADEN);	//enable ADC
}
/*void ReadADC(uint8_t channel, uint8_t *DataL, uint8_t *DataH, uint16_t *Data10)
{
	ADMUX &= ~(0x1F); //reset bit 0-4 ADMUX
	ADMUX |= channel; //mengakses data dari channel analog yang dipilih
	ADCSRA|= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);

	Lower = ADCL;
	Higher = ADCH;
	*DataL = Lower;
	*DataH = Higher;
	*Data10 = Higher*256 + Lower;
}*/

void BacaADC (uint8_t channel)
{
	ADMUX &= ~(0x1F); //reset bit 0-4 ADMUX
	ADMUX |= channel; //mengakses data dari channel analog yang dipilih
	ADCSRA|= (1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA |= (1<<ADIF);

	i=channel;
	Lower = ADCL;
	Higher = ADCH;
	sepuluhbit[i] = Higher*256 + Lower;
}

uint8_t ADCHigh (uint8_t channel)
{
	i=channel;
	BacaADC(i);
	return Higher;
}

uint8_t ADCLow (uint8_t channel)
{
	i=channel;
	BacaADC(i);
	return Lower;
}

/*void DataADC (void){
	for(i=0;i<3;i++){
		ReadADC(i,0,0,&dataADC[i]);
	}
}*/

uint8_t DigitalRAW(uint8_t channel){
	i=channel;
	//ReadADC(i,0,0,&dataADC[i]);
	BacaADC(i);
	//if (dataADC[i] < threshold[i]){
	if (sepuluhbit[i] < threshold[i]){
		DRAW[i] = 0;
	}
	else{
		DRAW[i] = 1;
	}
	return DRAW[i];
}

void CalibratingSensor(uint8_t channel){
	i=channel;
	//ReadADC(i,0,0,&dataADC[i]);
	BacaADC(i);
	//if (dataADC[i] > ADCMax[i]){
	if (sepuluhbit[i] > ADCMax[i]){
		ADCMax[i] = sepuluhbit[i];
	}
	else if (sepuluhbit[i] < ADCMin[i]){
		ADCMin[i] = sepuluhbit[i];
	}
	threshold[i] = (ADCMax[i]+ADCMin[i])/2;
}
