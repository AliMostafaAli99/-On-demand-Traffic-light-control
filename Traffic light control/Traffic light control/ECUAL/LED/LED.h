/*
 * LED.h
 *
 * Created: 9/29/2022 9:50:55 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer0/timer0.h"


// all function prototypes

void LED_init(uint8_t ledPort,uint8_t ledPin); //initialize LED 

void LED_ON(uint8_t ledPort,uint8_t ledPin); //LED_ON

void LED_OFF(uint8_t ledPort,uint8_t ledPin); //LED_OFF

void LED_blink_for_N_sec(uint8_t ledPort,uint8_t ledPin,uint8_t numberOfSecond); //LED_blink

void LED_both_blink_for_N_sec(uint8_t ledPort,uint8_t ledPin,uint8_t numberOfSecond,uint8_t ledPort2,uint8_t ledPin2); //Both_LED_blink 


#endif /* LED_H_ */