/*
 * uart.h
 *
 * Created: 02.05.2017 20:48:16
 *  Author: Jonas
 */ 


#ifndef UART_H_
#define UART_H_

#ifndef F_CPU
#define F_CPU 16000000UL //CPU Running at 16MHz
#endif

#include <avr/io.h>

#define _GET_UBBR(BAUD) ( (F_CPU / 16 * BAUD) - 1)

void uart_init(uint32_t _baud);

void uart_send(char _data);

void uart_send_string(char *_data);

char uart_recieve(void);

#endif /* UART_H_ */