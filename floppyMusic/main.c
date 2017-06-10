/*
 * floppyMusic.c
 *
 * Created: 29.04.2017 16:59:57
 * Author : Jonas
 */ 

 #ifndef F_CPU
 #define F_CPU 16000000UL //CPU Running at 16MHz
 #endif

#include <avr/io.h>

#include "floppy.h"
//#include "uart.h"

int main(void)
{
	//uart_init(9600);
	//DDRC = 0xff;
	floppy_setup(&PORTC, &DDRC, &PORTB, &DDRB);
	floppy_set_frequency(0, 70);

	DDRD = 0xff;

	PORTD = 0xff; //DEBUG

	//uart_send_string("Floppy Music\n");
    while (1) 
    {
		//floppy_set_frequency(0, uart_recieve());
		//uart_send_string("Floppy Music\n");
		//_delay_ms(500);
		//PORTD ^= 0xff;
    }
}