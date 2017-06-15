/*
 * midi.c
 *
 * Created: 12.06.2017 20:43:47
 *  Author: Jonas
 */ 

#include "midi.h"

void midi_setup()
{
	uart_init(9600);
}

void midi_recieve(struct midi_command *_command)
{
	if(!(UCSRB & (1<<RXEN))) //Return if UART reciever not enabled
		return;

	char status, data1, data2;
	char command, channel, note, velocity;

	status = uart_recieve();
	data1  = uart_recieve();
	data2  = uart_recieve();

	command = status & 0x0f; //Mask out last 4 bits 
	channel = (status >> 4) & 0x0f; // Shift channel into first 4 bits;
	note = data1;
	velocity = data2;

	_command->command = command;
	_command->channel=channel;
	_command->note = note;
	_command->velocity = velocity;

}

void midi_send(struct midi_command _command)
{

}