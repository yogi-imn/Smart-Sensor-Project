/*
 * uart.h
 *
 *  Created on: Sep 27, 2019
 *      Author: Yogi Iman
 */

#ifndef UART_H_
#define UART_H_

#define UART_BAUD_RATE 9600
#define VBAUDRATE (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
#define BAUDH VBAUDRATE / 256
#define BAUDL VBAUDRATE % 256
// Global function here
void USARTInit(void);
volatile unsigned char USARTGetChar(void);
void USARTPutChar(unsigned char data);
void USARTPutStr(char *text);
void USARTPutNum(int16_t number);

#endif /* UART_H_ */
