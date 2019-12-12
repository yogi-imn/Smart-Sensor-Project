/*
 * uart.h
 *
 *  Created on: Dec 6, 2019
 *      Author: asus
 */

#ifndef UART_H_
#define UART_H_

#define BAUDRATE 9600
#define VBAUDRATE (F_CPU/((unsigned long) BAUDRATE*16)-1)
#define BAUDH VBAUDRATE / 256
#define BAUDL VBAUDRATE % 256
// Global function here
void USARTInit(void);
volatile unsigned char USARTGetChar(void);
void USARTPutChar(unsigned char data);
void USARTPutStr(char *text);
void USARTPutNum(uint16_t number);

#endif /* UART_H_ */
