/*
 * music.h
 *
 * Created: 12.06.2017 18:59:36
 *  Author: Jonas
 */ 


#ifndef MUSIC_H_
#define MUSIC_H_

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

#ifndef F_CPU
#define F_CPU 16000000UL //CPU Running at 16MHz
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "floppy.h"

void beep(int _f, unsigned int _t);

void delay_ms(unsigned int ms );

void play_imperial_march();

void play_tetris();

#endif /* MUSIC_H_ */