/*
 * uart.c
 *
 *  Created on: Dec 6, 2019
 *      Author: asus
 */

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "uart.h"

void USARTInit(void) {
	// setup baudrate
	UBRR0H = BAUDH;
	UBRR0L = BAUDL;
	// Enable Receiver and Transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	//Set frame format: 8data, 1stop bit
	UCSR0C = (0 << USBS0) | (3 << UCSZ00);
}
volatile unsigned char USARTGetChar(void) {
	//Wait for data for to be received
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}
void USARTPutChar(unsigned char data) {
	//Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}
void USARTPutStr(char *text) {
	while(*text){
		USARTPutChar(*text++);
	}
}
void USARTPutNum(int16_t number){
	char buff[20];
	sprintf(buff,"%d",number);
	USARTPutStr(buff);
}
