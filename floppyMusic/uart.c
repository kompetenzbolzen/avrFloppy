/*
 * uart.c
 *
 * Created: 02.05.2017 20:48:26
 *  Author: Jonas
 */ 

 #include "uart.h"

 void uart_init(uint32_t _baud)
 {
	unsigned int ubrr = _GET_UBBR(_baud);

	UBRRH = (ubrr<<8);
	UBRRL = ubrr;
 }

 void uart_send(char _data)
 {
	while(!(UCSRA & (1<<UDRE)));
	UDR = _data;
 }

 void uart_send_string(char *_data)
 {
	char *data = _data;

	while(*data != '\0')
	{
		uart_send(*data);
		data++;
	}
 }

 char uart_recieve()
 {
	while(!(UCSRA & (1<<RXC)));

	return UDR;
 }