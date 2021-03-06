/*
 * floppy.c
 *
 * Created: 29.04.2017 17:06:37
 *  Author: Jonas
 */ 

 #include "floppy.h"

ISR(TIMER0_OVF_vect)
{
	timer_overflow_counter ++;

	*fPORT = 0xff; //Deactivate all previously activated pins

	for(uint8_t i = 0; i < 8; i++) //Perform check of every channel
	{
		if(floppy_nextrun[i] == timer_overflow_counter && floppy_frequencies[i] > 0) //check if pulse is due
		{
			floppy_nextrun[i] += floppy_frequencies[i]; //set next pulse
			floppy_pulse(i);
		}
	}
}

void floppy_setup(unsigned char *_pulse_port, unsigned char *_pulse_ddr, unsigned char *_direction_port, unsigned char *_direction_ddr)
 {
	//Setup Ports
	fPORT	= _pulse_port;
	fDDR	= _pulse_ddr;
	dPORT	= _direction_port;
	dDDR	= _direction_ddr;
	
	//Floppy inputs are active low so they are initialized high
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

	*dPORT	= 0x00; //Head needs to be reversed
	*fPORT	= 0xff;

	//Setup Timer
	TCCR0	|= (1 << CS01); // Prescaler 8 To leave enough time for ISR to complete
	TIMSK	|= (1 << TOIE0); //Activate Interrupt

	sei();
 }

 void floppy_set_frequency(uint8_t _floppy_id, uint8_t _freq)
 {
	floppy_frequencies[_floppy_id] = _freq;
	floppy_nextrun[_floppy_id] = _freq + timer_overflow_counter;
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

 uint8_t floppy_calc_freq(uint32_t _f_hz)
 {
	uint32_t f = _f_hz;

	if(_f_hz < 31)
		return 255;
	if(_f_hz > 400) //FDD cant go over 400Hz so the tone is shifted down in octaves
		for(f = _f_hz; f > 400; f /= 2);

	return 7913 / f;
 }