/*
 * uart.c
 *
 * Created: 02.05.2017 20:48:26
 *  Author: Jonas
 */ 

 #include "uart.h"

 void uart_init(unsigned int _baud)
 {
	unsigned  int ubrr =  (F_CPU / (16 * _baud))  - 1;

	 UBRRH = (unsigned char)(ubrr>>8) & 0xff;
	 UBRRL = (unsigned char)ubrr & 0xff;

	 UCSRB = (1<<RXEN)|(1<<TXEN);
	 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
 }

 void uart_send(char _data)
 {
	 while(!(UCSRA & (1<<UDRE))); //Wait for previous data to be sent
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
	 while(!(UCSRA & (1<<RXC))); //Wait for data

	 return UDR;
 }


