/*
 * timer0.h
 *
 * Created: 9/30/2022 5:28:06 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/Register.h"


// extern global variable that will be use to handle the sequence
uint8_t Pedestrian_mode  ;

// all function prototypes

void timer0_init(void);

void delay500ms (void);

void delay_5_sec (void);



#endif /* TIMER0_H_ */