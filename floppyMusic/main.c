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
#include "music.h"
#include "uart.h"

int main(void)
{
	uart_init(9600);
	floppy_setup(&PORTC, &DDRC, &PORTB, &DDRB);
	DDRA = 0xff;
	uart_send_string("Hallo\n");

    while (1) 
    {
		play_imperial_march();
		_delay_ms(2000);
		uart_send_string("Hallo\n");
    }
}

