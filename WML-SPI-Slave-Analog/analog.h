/*
 * analog.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Yogi Iman
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#include<avr/io.h>
unsigned int ADCIN (unsigned char channel);
void ADCInit(void);
void ReadADC(uint8_t channel, uint8_t *DataL, uint8_t *DataH, uint16_t *Data10);
void DataADC (void);
uint8_t DigitalRAW(uint8_t channel);
void BacaADC (uint8_t channel);
uint8_t ADCHigh (uint8_t channel);
uint8_t ADCLow (uint8_t channel);
void CalibratingSensor(uint8_t channel);

#endif /* ANALOG_H_ */
