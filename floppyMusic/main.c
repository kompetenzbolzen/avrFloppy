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
#include "uart.h"

int main(void)
{
	uart_init(9600);

	floppy_setup(&PORTC, &DDRC, &PORTD, &DDRD);
	floppy_set_frequency(0, 4);

	uart_send_string("Floppy Music\n");

    while (1) 
    {
		floppy_set_frequency(0, uart_recieve());
    }
}