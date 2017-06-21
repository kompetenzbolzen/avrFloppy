/*
 * floppyMusic.c
 *
 * Created: 29.04.2017 16:59:57
 * Author : Jonas
 */ 

#define _TEST_MODE

#include <avr/io.h>

#include "floppy.h"
#include "midi.h"

#ifdef _TEST_MODE
#include "music.h"
#endif

int main(void)
{
	floppy_setup(&PORTC, &DDRC, &PORTB, &DDRB);

	#ifdef _TEST_MODE //Play imperial March in test mode

	DDRA = 0xff;

    for(;;)
    {
		play_imperial_march();
		_delay_ms(2000);
    }

	#else //Normal MIDI mode

	midi_setup();

	for(;;);

	#endif

}

