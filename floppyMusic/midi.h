/*
 * midi.h
 *
 * Created: 12.06.2017 20:43:37
 *  Author: Jonas
 */ 


#ifndef MIDI_H_
#define MIDI_H_

#define _MIDI_SEND 0
#define _MIDI_RECIEVE 1

#include "uart.h"

struct midi_command
{
	char command;
	char channel;
	char note;
	char velocity;
};


void midi_setup();

void midi_recieve(struct midi_command *_command);

void midi_send(struct midi_command _command);



#endif /* MIDI_H_ */