/*
 * midi.c
 *
 * Created: 12.06.2017 20:43:47
 *  Author: Jonas
 */ 

#include "midi.h"

const uint16_t midi_code_frequency_table[] = {8,9,9,10,10,11,12,12,13,14,15,15,16,17,18,19,21,22,23,25,26,28,29,31,33,35,37,39,41,44,46,49,52,55,58,62,65,69,73,78,82,87,93,98,104,110,117,123,131,139,147,156,165,175,185,196,208,220,233,247,262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784,831,880,932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,4435,4699,4978,5274,5588,5920,6272};

ISR(USART_RXC_vect)
{
	char data[3] = {0x00, 0x00, 0x00};
	char command, /*channel,*/ note/*, velocity*/;

	UCSRB &= ~(1<<RXCIE);//Disable UART interrupt

	//read data from interface
	while(!(UCSRA & (1<<RXC))); //Wait for data
	data[0] = UDR;

	for(int i = 0; i < 20; i++) { //Wait 100µs for next datapackage
		_delay_us(1);
		if((UCSRA & (1<<RXC))) {
			data[1] = UDR;
			break;
		}
	}
	for(int i = 0; i < 20; i++) {
		_delay_us(1);
		if((UCSRA & (1<<RXC))) {
			data[2] = UDR;
			break;
		}
	}
	UCSRB |= (1<<RXCIE);//reenable UART Interrupt

	//split data
	/*channel = data[0] & 0x0f; //Mask out last 4 bits*/
	command = (data[0] >> 4) & 0x0f; // Shift command into first 4 bits;
	note = data[1];
	/*velocity = data2;*/
	
	//PORTA = ~command;
	
	switch(command)
	{
		case 0x08: //Note off
			PORTA = 1;
			midi_update_note(note, 0);
		break;
			
		case 0x09: //Note on
			PORTA = 2;
			midi_update_note(note, 1);
		break;
		/*
		case 0x0A:break; //Note Fade Out
		
		case 0x0B:break; //Control Change

		case 0x0C:break; //Channel Fade Out

		case 0x0E:break; //Note Pitch change
		*/
		default:break;
	}
}

void midi_setup()
{
	midi_active_channels = 0x00;
	DDRA = 0xff;
	PORTA = 0xff;
	//UART init
	unsigned  int ubrr   = (F_CPU / (16 * _MIDI_LINK_SPEED))  - 1;

	UBRRH = (unsigned char) (ubrr>>8) & 0xff;
	UBRRL = (unsigned char) ubrr & 0xff;

	UCSRB = (1<<RXEN)  | (1<<TXEN) | (1<<RXCIE); //Enable Tx, Rx and Rx Interrupt
	UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);

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
