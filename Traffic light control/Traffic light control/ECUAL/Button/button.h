/*
 * button.h
 *
 * Created: 9/29/2022 10:27:39 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/dio.h"


// all function prototypes

// initialize
void button_init(uint8_t buttonPort,uint8_t buttonPin); //initialize button


//button read
void button_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value); //read button state


#endif /* BUTTON_H_ */