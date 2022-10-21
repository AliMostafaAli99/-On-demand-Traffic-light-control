/*
 * LED.c
 *
 * Created: 9/29/2022 9:51:24 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 

// include .h
#include "../../MCAL/DIO/dio.h"
#include "LED.h"


// function definitions


void LED_init(uint8_t ledPort,uint8_t ledPin)
{
	DIO_init(ledPort,ledPin,OUTPUT);
}

void LED_ON(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);
}

void LED_OFF(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LOW);
}

void LED_blink_for_N_sec(uint8_t ledPort,uint8_t ledPin,uint8_t numberOfSecond)
{
	uint8_t counter = 0 ;
	while (counter < numberOfSecond)
	{
		// LED ON
		DIO_write(ledPort,ledPin,HIGH);
		
		// delay for blink
		delay500ms();
		
		// LED OFF
		DIO_write(ledPort,ledPin,LOW);
		
		// delay for blink
		delay500ms();
		
		// one loop equal 1 sec
		
		if (Pedestrian_mode== 1) {break;}
		
		counter++;
	}
}
void LED_both_blink_for_N_sec(uint8_t ledPort,uint8_t ledPin,uint8_t numberOfSecond,uint8_t ledPort2,uint8_t ledPin2)
{
	uint8_t counter = 0 ;
	while (counter < numberOfSecond)
	{
		// Both LED ON
		DIO_write(ledPort,ledPin,HIGH);
		DIO_write(ledPort2,ledPin2,HIGH);
		
		// delay for blink
		delay500ms();
		
		// Both LED OFF
		DIO_write(ledPort,ledPin,LOW);
		DIO_write(ledPort2,ledPin2,LOW);
		
		// delay for blink
		delay500ms();
		
		// one loop equal 1 sec
		
		counter++;
	}
}
