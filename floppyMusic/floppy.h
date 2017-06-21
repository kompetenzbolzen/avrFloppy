/*
 * floppy.h
 *
 * Created: 29.04.2017 17:06:28
 *  Author: Jonas
 */ 


#ifndef FLOPPY_H_
#define FLOPPY_H_

#ifndef F_CPU
#error F_CPU not defined for floppy.h
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t timer_overflow_counter;
uint8_t floppy_frequencies[8];
uint8_t floppy_nextrun[8];
uint8_t floppy_head_return_counter[8];

unsigned char *fPORT, *fDDR, *dPORT, *dDDR; //Ports for floppy and Direction of Heads

void floppy_setup(unsigned char *_pulse_port, unsigned char *_pulse_ddr, unsigned char *_direction_port, unsigned char *_direction_ddr);
/*
* *_pulse_port : port where stepper is connected, eg &PORTA
* *_pulse_ddr  : its direction register, eg &DDRA
* *_direction_port : Port where direction pins are connected, eg &PORTB
* *_direction_ddr  : its direction register, eg &DDRB
*/
void floppy_set_frequency(uint8_t _floppy_id, uint8_t _freq);
/*
* _floppy_id : [0-7] channel select
* _freq : [0-255] numerical value representing frequency. use floppy_calc_freq() to calculate from frequency in Hz
*/

void floppy_pulse(uint8_t _floppy_id);
/*
* pulses FDD, keeps track of when to apply head-reverse signal
* _floppy_id : [0-7] channel select
*/

uint8_t floppy_calc_freq(uint32_t _f_hz);
/*
* Converts frequency in Hz into value used by floppy_set_frequency()
* _f_hz : Frequency in Hz
*/


#endif /* FLOPPY_H_ */