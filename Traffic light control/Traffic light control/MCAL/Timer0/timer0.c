/*
 * timer0.c
 *
 * Created: 9/30/2022 5:28:21 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 

// include .h
#include "timer0.h"

//global variable that will be use to handle the sequence
uint8_t Pedestrian_mode = 0;


// function definitions
void timer0_init(void)
{
	//choose timer mode
	TCCR0 = 0x00;  // normal mode
	
	// timer set initial value
	TCNT0 =0x00; 
	
}

void delay500ms (void)
{
	// timer start -> setting the clock sorce
	
	TCCR0 |= (1<<0);  // clkI/O/(No prescaling)
	
	unsigned int overflowCounter = 0 ;
	
	while (overflowCounter<2000)
	{
		// will be repeated 2000 times
		
		//wait until the overflow flag to be set 
		while ((TIFR & (1<<0)) == 0 );
		
		//clear the overflow flag
		TIFR |=  (1<<0);
		
		
		
		overflowCounter++;
	}
	
	//timer stop
	TCCR0 = 0x00;
}

void delay_5_sec (void)
{
	// timer start -> setting the clock sorce
	
	TCCR0 |= (1<<0);  // clkI/O/(No prescaling)
	
	unsigned int overflowCounter = 0 ;
	
	while (overflowCounter<20000)
	{
		// wile be repeated 2000 times
		
		//wait until the overflow flag to be set
		while ((TIFR & (1<<0)) == 0 );
		
		//clear the overflow flag
		TIFR |=  (1<<0);
		
		if (Pedestrian_mode== 1) {break;}
		
		overflowCounter++;
	}
	
	//timer stop
	TCCR0 = 0x00;
}