/*
 * floppy.c
 *
 * Created: 29.04.2017 17:06:37
 *  Author: Jonas
 */ 

 #include "floppy.h"

ISR(TIMER0_OVF_vect)
{
	cli();

	timer_overflow_counter ++;

	*fPORT = 0xff;

	for(uint8_t i = 0; i < 8; i++)
	{
		if(floppy_nextrun[i] == (timer_overflow_counter + 1)) //Do Stuff. Doesnt work
		{
			floppy_nextrun[i] += floppy_frequencies[i];
			floppy_pulse(i);
		}
	}

	sei();
}

void floppy_setup(char *_pulse_port, char *_pulse_ddr, char *_direction_port, char *_direction_ddr)
 {
	//Setup Ports
	fPORT	= _pulse_port;
	fDDR	= _pulse_ddr;
	dPORT	= _direction_port;
	dDDR	= _direction_ddr;

	*fDDR	= 0xff;
	*fPORT	= 0xff;
	*dDDR	= 0xff;
	*dPORT	= 0xff;
	
	

	//Variable init
	timer_overflow_counter = 0;

	for(uint8_t i = 0; i < 8; i++)
	{
		floppy_head_return_counter[i] = 0;
		floppy_frequencies[i] = 0;
		floppy_nextrun[i] = 0;
	}

	//Return all FDDs to track 0

	for(uint8_t i = 0; i < 200; i++)
	{
		_delay_ms(5);
		*fPORT ^= 0xff;
	}

	*fPORT	= 0xff;

	//Setup Timer
	TCCR0	|= (1 << CS01); // Prescaler 8, for max Frequency of 488 Hertz for F_CPU = 1MHz
	TIMSK	|= (1 << TOIE0); //Activate Interrupt
	sei();
 }

 void floppy_set_frequency(uint8_t _floppy_id, uint8_t _freq)
 {
	floppy_frequencies[_floppy_id] = floppy_nextrun[_floppy_id] = _freq;
 }

 void floppy_pulse(uint8_t _floppy_id)
 {
	*fPORT &= ~(1 << _floppy_id); //Activate pin

	floppy_head_return_counter[_floppy_id] ++;

	if(floppy_head_return_counter[_floppy_id] > 75) //Toggle direction pin if more than 75 steps performed
	{
		*dPORT ^= (1<<_floppy_id);
		floppy_head_return_counter[_floppy_id] = 0;
	}
 }