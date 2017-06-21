/*
 * midi.h
 *
 * Created: 12.06.2017 20:43:37
 *  Author: Jonas
 */ 

#ifndef F_CPU
#error F_CPU not defined for midi.h
#endif

#ifndef MIDI_H_
#define MIDI_H_

#define _MIDI_LINK_SPEED 30000UL //Standard MIDI linkspeed is 30k baud



#include <avr/interrupt.h>
#include <avr/io.h>

#include "floppy.h"

char midi_active_channels;
uint16_t midi_current_notes[8];
const uint16_t midi_code_frequency_table[232];

void midi_setup();
/*
* initializes UART communication and Interrupts
*/

void midi_update_note(uint16_t _note, uint8_t _status);
/*
* _note : MIDI standard note #
* _status : 0=OFF >0=ON
*/

char midi_recieve();
/*
* reads UART recieve buffer 
*/


#endif /* MIDI_H_ */