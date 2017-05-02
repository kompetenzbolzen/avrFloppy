/*
 * floppy.h
 *
 * Created: 29.04.2017 17:06:28
 *  Author: Jonas
 */ 


#ifndef FLOPPY_H_
#define FLOPPY_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t timer_overflow_counter;
uint8_t floppy_frequencies[8];
uint8_t floppy_nextrun[8];
uint8_t floppy_head_return_counter[8];

char *fPORT, *fDDR, *dPORT, *dDDR; //Ports for floppy and Direction of Heads

void floppy_setup(char *_pulse_port, char *_pulse_ddr, char *_direction_port, char *_direction_ddr);

void floppy_set_frequency(uint8_t _floppy_id, uint8_t _freq);

void floppy_pulse(uint8_t _floppy_id);


#endif /* FLOPPY_H_ */