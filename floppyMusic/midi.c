/*
 * midi.c
 *
 * Created: 12.06.2017 20:43:47
 *  Author: Jonas
 */ 

 /*
  Octave||                     Note Numbers
	 #  ||
	    || C   | C#  | D   | D#  | E   | F   | F#  | G   | G#  | A   | A#  | B
 -----------------------------------------------------------------------------
	 0  ||   0 |   1 |   2 |   3 |   4 |   5 |   6 |   7 |   8 |   9 |  10 | 11
	 1  ||  12 |  13 |  14 |  15 |  16 |  17 |  18 |  19 |  20 |  21 |  22 | 23
	 2  ||  24 |  25 |  26 |  27 |  28 |  29 |  30 |  31 |  32 |  33 |  34 | 35
	 3  ||  36 |  37 |  38 |  39 |  40 |  41 |  42 |  43 |  44 |  45 |  46 | 47
	 4  ||  48 |  49 |  50 |  51 |  52 |  53 |  54 |  55 |  56 |  57 |  58 | 59
	 5  ||  60 |  61 |  62 |  63 |  64 |  65 |  66 |  67 |  68 |  69 |  70 | 71
	 6  ||  72 |  73 |  74 |  75 |  76 |  77 |  78 |  79 |  80 |  81 |  82 | 83
	 7  ||  84 |  85 |  86 |  87 |  88 |  89 |  90 |  91 |  92 |  93 |  94 | 95
	 8  ||  96 |  97 |  98 |  99 | 100 | 101 | 102 | 103 | 104 | 105 | 106 | 107
	 9  || 108 | 109 | 110 | 111 | 112 | 113 | 114 | 115 | 116 | 117 | 118 | 119
	 10 || 120 | 121 | 122 | 123 | 124 | 125 | 126 | 127 |
 */

#include "midi.h"

extern const uint16_t midi_code_frequency_table[] = {8,9,9,10,10,11,12,12,13,14,15,15,16,17,18,19,21,22,23,25,26,28,29,31,33,35,37,39,41,44,46,49,52,55,58,62,65,69,73,78,82,87,93,98,104,110,117,123,131,139,147,156,165,175,185,196,208,220,233,247,262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784,831,880,932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,4435,4699,4978,5274,5588,5920,6272};

ISR(USART_RXC_vect)
{
	cli();
	char status, data1, data2;
	char command, channel, note, velocity;

	//read data from interface
	status = midi_recieve();
	data1  = midi_recieve();
	data2  = midi_recieve();

	sei();

	//split data
	command = status & 0x0f; //Mask out last 4 bits
	channel = (status >> 4) & 0x0f; // Shift channel into first 4 bits;
	note = data1;
	velocity = data2;

	switch(command)
	{
		case 0x08: //Note off
			midi_update_note(note, 0);
		break;
			midi_update_note(note, 1);
		case 0x09: //Note on
			
		break;

		case 0x0A: //Note Fade Out
			//unused
		break;

		case 0x0B: //Control Change
			//unused
		break;

		case 0x0C: //Channel Fade Out
			//unused
		break;

		case 0x0E: //Note Pitch change
			//unused
		break;
	}
	

}

void midi_setup()
{
	midi_active_channels = 0x00;

	//UART init
	unsigned  int ubrr   = (F_CPU / (16 * _MIDI_LINK_SPEED))  - 1;

	UBRRH = (unsigned char) (ubrr>>8) & 0xff;
	UBRRL = (unsigned char) ubrr & 0xff;

	UCSRB = (1<<RXEN)  | (1<<TXEN);
	UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);

	UCSRB |= (1<<RXCIE); //enable interrupt
}

 char midi_recieve()
 {
	 while(!(UCSRA & (1<<RXC))); //Wait for data

	 return UDR;
 }

 void midi_update_note(uint16_t _note, uint8_t _status)
 {
	if(_status) //Note on
	{
		int i;
		for(i = 0; i < 8; i++) //search for first free channel
			if(!(midi_active_channels & (1<<i)))
				break;

		midi_current_notes[i] = _note; //write current note to channel
		midi_active_channels |= (1<<i); //set channel active
		floppy_set_frequency(i, floppy_calc_freq(midi_code_frequency_table[_note]) ); //play note
	}

	else //Note off
	{
		int i;
		for(i = 0; i < 8; i++) //search for active channel playing _note
		{
			if(midi_current_notes[i] == _note)
			{
				floppy_set_frequency(i, 0); //mute
				midi_current_notes[i] = 0xff; //unset current, 0xff is outside MIDI standards
				midi_active_channels &= ~(1<<i); //unset channel active
				break;
			}
		}
	}
 }
