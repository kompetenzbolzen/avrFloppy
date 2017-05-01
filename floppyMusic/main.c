/*
 * floppyMusic.c
 *
 * Created: 29.04.2017 16:59:57
 * Author : Jonas
 */ 

#include <avr/io.h>

#include "floppy.h"

int main(void)
{
	floppy_setup(&PORTC, &DDRC, &PORTD, &DDRD);
	floppy_set_frequency(0, 4);

    while (1) 
    {
		
    }
}

