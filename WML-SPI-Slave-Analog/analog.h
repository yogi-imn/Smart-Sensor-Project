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
uint16_t ReadADC(uint8_t channel);
uint16_t dataADC;
uint16_t DataADCH(uint8_t channel);
uint16_t DataADCL(uint8_t channel);
uint16_t DigitalRAW(uint8_t channel);
uint16_t CalibratingS0(uint8_t channel);

#endif /* ANALOG_H_ */
