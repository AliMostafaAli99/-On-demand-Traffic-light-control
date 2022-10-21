/*
 * dio.c
 *
 * Created: 9/29/2022 8:15:01 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 

// include .h
#include "dio.h"


// global variables



// function definitions
EN_DIO_error_t DIO_init(uint8_t portNumber,uint8_t pinNumber, uint8_t direction)
{
	//error handling
	if (pinNumber <0 || pinNumber >7) return DIO_WRONG_PIN_NUMBER ;
	

	switch(portNumber)
	{
		case PORT_A:
		if (direction==INPUT)
		{
			DDRA &= ~ (1<<pinNumber); //clear
		}
		else if (direction==OUTPUT)
		{
			DDRA |=  (1<<pinNumber); //set
		}
		else
		{
			//error handling
			return DIO_WRONG_DIRECTION ;
		}
		break;
		
		case PORT_B:
		if (direction==INPUT)
		{
			DDRB &= ~ (1<<pinNumber);
		}
		else if (direction==OUTPUT)
		{
			DDRB |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_DIRECTION ;
		}
		break;
		
		case PORT_C:
		if (direction==INPUT)
		{
			DDRC &= ~ (1<<pinNumber);
		}
		else if (direction==OUTPUT)
		{
			DDRC |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_DIRECTION ;
		}
		break;
		case PORT_D:
		if (direction==INPUT)
		{
			DDRD &= ~ (1<<pinNumber);
		}
		else if (direction==OUTPUT)
		{
			DDRD |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_DIRECTION ;
		}
		break;
		
		default: //error handling
		return DIO_WRONG_PORT_NUMBER;
		break;
		
	}
	return DIO_OK;
}

EN_DIO_error_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
	//error handling
	if (pinNumber <0 || pinNumber >7) return DIO_WRONG_PIN_NUMBER ;
	
	switch(portNumber)
	{
		case PORT_A:
		if (value==LOW)
		{
			PORTA &= ~ (1<<pinNumber);
		}
		else if (value==HIGH)
		{
			PORTA |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_VALUE ;
		}
		break;
		
		case PORT_B:
		if (value==LOW)
		{
			PORTB &= ~ (1<<pinNumber);
		}
		else if (value==HIGH)
		{
			PORTB |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_VALUE ;
		}
		break;
		
		case PORT_C:
		if (value==LOW)
		{
			PORTC &= ~ (1<<pinNumber);
		}
		else if (value==HIGH)
		{
			PORTC |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_VALUE ;
			
		}
		break;
		case PORT_D:
		if (value==LOW)
		{
			PORTD &= ~ (1<<pinNumber);
		}
		else if (value==HIGH)
		{
			PORTD |=  (1<<pinNumber);
		}
		else
		{
			//error handling
			return DIO_WRONG_VALUE ;
		}
		break;
		
		default: //error handling
		return DIO_WRONG_PORT_NUMBER;
		break;
		
	}
	return DIO_OK;
}



EN_DIO_error_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value)
{
	//error handling
	if (pinNumber <0 || pinNumber >7) return DIO_WRONG_PIN_NUMBER ;
	
	switch(portNumber)
	{
		case PORT_A:
		*value= (PINA & (1<< pinNumber))>> pinNumber;
		break;
		
		case PORT_B:
		*value= (PINB & (1<< pinNumber))>> pinNumber;
		break;
		
		case PORT_C:
		*value= (PINC & (1<< pinNumber))>> pinNumber;
		break;
		
		case PORT_D:
		*value= (PIND & (1<< pinNumber))>> pinNumber;
		break;
		
		default: //error handling
		return DIO_WRONG_PORT_NUMBER;
		break;
		
	}
	return DIO_OK;
}