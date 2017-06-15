/*
 * music.c
 *
 * Created: 12.06.2017 18:59:47
 *  Author: Jonas
 */ 

 #include "music.h"

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

 void play_tetris()
 {
	 beep(658, 125);
	 beep(1320, 500);
	 beep(990, 250);
	 beep(1056, 250);
	 beep(1188, 250);
	 beep(1320, 125);
	 beep(1188, 125);
	 beep(1056, 250);
	 beep(990, 250);
	 beep(880, 500);
	 beep(880, 250);
	 beep(1056, 250);
	 beep(1320, 500);
	 beep(1188, 250);
	 beep(1056, 250);
	 beep(990, 750);
	 beep(1056, 250);
	 beep(1188, 500);
	 beep(1320, 500);
	 beep(1056, 500);
	 beep(880, 500);
	 beep(880, 500);
	 _delay_ms(250);
	 beep(1188, 500);
	 beep(1408, 250);
	 beep(1760, 500);
	 beep(1584, 250);
	 beep(1408, 250);
	 beep(1320, 750);
	 beep(1056, 250);
	 beep(1320, 500);
	 beep(1188, 250);
	 beep(1056, 250);
	 beep(990, 500);
	 beep(990, 250);
	 beep(1056, 250);
	 beep(1188, 500);
	 beep(1320, 500);
	 beep(1056, 500);
	 beep(880, 500);
	 beep(880, 500);
	 _delay_ms(500);
	 beep(1320, 500);
	 beep(990, 250);
	 beep(1056, 250);
	 beep(1188, 250);
	 beep(1320, 125);
	 beep(1188, 125);
	 beep(1056, 250);
	 beep(990, 250);
	 beep(880, 500);
	 beep(880, 250);
	 beep(1056, 250);
	 beep(1320, 500);
	 beep(1188, 250);
	 beep(1056, 250);
	 beep(990, 750);
	 beep(1056, 250);
	 beep(1188, 500);
	 beep(1320, 500);
	 beep(1056, 500);
	 beep(880, 500);
	 beep(880, 500);
	 _delay_ms(250);
	 beep(1188, 500);
	 beep(1408, 250);
	 beep(1760, 500);
	 beep(1584, 250);
	 beep(1408, 250);
	 beep(1320, 750);
	 beep(1056, 250);
	 beep(1320, 500);
	 beep(1188, 250);
	 beep(1056, 250);
	 beep(990, 500);
	 beep(990, 250);
	 beep(1056, 250);
	 beep(1188, 500);
	 beep(1320, 500);
	 beep(1056, 500);
	 beep(880, 500);
	 beep(880, 500);
	 _delay_ms(500);
	 beep(660, 1000);
	 beep(528, 1000);
	 beep(594, 1000);
	 beep(495, 1000);
	 beep(528, 1000);
	 beep(440, 1000);
	 beep(419, 1000);
	 beep(495, 1000);
	 beep(660, 1000);
	 beep(528, 1000);
	 beep(594, 1000);
	 beep(495, 1000);
	 beep(528, 500);
	 beep(660, 500);
	 beep(880, 1000);
	 beep(838, 2000);
	 beep(660, 1000);
	 beep(528, 1000);
	 beep(594, 1000);
	 beep(495, 1000);
	 beep(528, 1000);
	 beep(440, 1000);
	 beep(419, 1000);
	 beep(495, 1000);
	 beep(660, 1000);
	 beep(528, 1000);
	 beep(594, 1000);
	 beep(495, 1000);
	 beep(528, 500);
	 beep(660, 500);
	 beep(880, 1000);
	 beep(838, 2000);

 }

 void beep(int _f, unsigned int _t)
 {
	 PORTA = ~ floppy_calc_freq(_f / 3);

	 floppy_set_frequency(0, floppy_calc_freq(_f /3) );
	 floppy_set_frequency(1, floppy_calc_freq(_f /3) );

	 delay_ms(_t);

	 PORTA = 0xff;

	 floppy_set_frequency(0, 0);
	 floppy_set_frequency(1, 0);

	 delay_ms(10);
 }