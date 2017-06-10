/*
 * floppyMusic.c
 *
 * Created: 29.04.2017 16:59:57
 * Author : Jonas
 */ 

 #define c 130
 #define d 147
 #define e 165
 #define f 175
 #define g 195
 #define gS 208
 #define a 220
 #define aS 228
 #define b 233
 #define cH 261
 #define cSH 277
 #define dH 294
 #define dSH 311
 #define eH 330
 #define fH 349
 #define fSH 370
 #define gH 390
 #define gSH 415
 #define aH 440

 #define _GET_UBBR(BAUD) ( (F_CPU / 16 * BAUD) - 1)

 #ifndef F_CPU
 #define F_CPU 16000000UL //CPU Running at 16MHz
 #endif

#include <avr/io.h>

#include "floppy.h"

void imperial_march();

void beep(int _f, unsigned int _t);

void delay_ms(unsigned int ms );

 
int main(void)
{
	floppy_setup(&PORTC, &DDRC, &PORTB, &DDRB);

	floppy_set_frequency(0, 0);
	floppy_set_frequency(1, 0);
	DDRD = 0xff;

    while (1) 
    {
		play_imperial_march();
		_delay_ms(2000);
    }
}

void delay_ms(unsigned int ms )
{
	unsigned int i;
	for (i = 0; i<= ms; i++)
		_delay_ms(1);
}

void play_imperial_march()
{
	 beep(a, 500);
	 beep(a, 500);
	 beep(a, 500);
	 beep(f, 350);
	 beep(cH, 150);
	 beep(a, 500);
	 beep(f, 350);
	 beep(cH, 150);
	 beep(a, 650);
	 
	 delay_ms(150);
	 //end of first bit
	 
	 beep(eH, 500);
	 beep(eH, 500);
	 beep(eH, 500);
	 beep(fH, 350);
	 beep(cH, 150);
	 beep(gS, 500);
	 beep(f, 350);
	 beep(cH, 150);
	 beep(a, 650);
	 
	 delay_ms(150);
	 //end of second bit...
	 
	 beep(aH, 500);
	 beep(a, 300);
	 beep(a, 150);
	 beep(aH, 400);
	 beep(gSH, 200);
	 beep(gH, 200);
	 beep(fSH, 125);
	 beep(fH, 125);
	 beep(fSH, 250);
	 
	 delay_ms(250);
	 
	 beep(aS, 250);
	 beep(dSH, 400);
	 beep(dH, 200);
	 beep(cSH, 200);
	 beep(cH, 125);
	 beep(b, 125);
	 beep(cH, 250);
	 
	 delay_ms(250);
	 
	 beep(f, 125);
	 beep(gS, 500);
	 beep(f, 375);
	 beep(a, 125);
	 beep(cH, 500);
	 beep(a, 375);
	 beep(cH, 125);
	 beep(eH, 650);
	 
	 //end of third bit... (Though it doesn't play well)
	 //let's repeat it
	 
	 beep(aH, 500);
	 beep(a, 300);
	 beep(a, 150);
	 beep(aH, 400);
	 beep(gSH, 200);
	 beep(gH, 200);
	 beep(fSH, 125);
	 beep(fH, 125);
	 beep(fSH, 250);
	 
	 delay_ms(250);
	 
	 beep(aS, 250);
	 beep(dSH, 400);
	 beep(dH, 200);
	 beep(cSH, 200);
	 beep(cH, 125);
	 beep(b, 125);
	 beep(cH, 250);
	 
	 delay_ms(250);
	 
	 beep(f, 250);
	 beep(gS, 500);
	 beep(f, 375);
	 beep(cH, 125);
	 beep(a, 500);
	 beep(f, 375);
	 beep(cH, 125);
	 beep(a, 650);
	 //end of the song
}

void beep(int _f, unsigned int _t)
{
	PORTD = ~ floppy_calc_freq(_f / 3);
	floppy_set_frequency(0, floppy_calc_freq(_f / 3));
	floppy_set_frequency(1, floppy_calc_freq(_f / 3));
	delay_ms(_t);
	PORTD = 0xff;
	floppy_set_frequency(0, 0);
	floppy_set_frequency(1, 0);
	_delay_ms(10);
}