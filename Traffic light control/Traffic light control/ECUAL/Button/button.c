/*
 * button.c
 *
 * Created: 9/29/2022 10:27:18 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 
// include .h
#include "../../MCAL/DIO/dio.h"
#include "button.h"

// global variables



// function definitions

void button_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_init(buttonPort,buttonPin,INPUT); //button is an input device
}


void button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value)
{
	DIO_read(buttonPort,buttonPin,value);
}
