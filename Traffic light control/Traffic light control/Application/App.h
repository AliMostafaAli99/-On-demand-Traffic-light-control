/*
 * App.h
 *
 * Created: 9/29/2022 11:08:18 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 


#ifndef APP_H_
#define APP_H_

// Include lower layer .h
#include "../MCAL/DIO/dio.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/button.h"
#include "../MCAL/Interrupt library/interrupt.h"
#include "../MCAL/Timer0/timer0.h"
#include "../Utilities/Register.h"

// all internal driver typedefs


/* all driver macros */
// Pedestrian_button:Port and Pin defines
#define Pedestrian_button_port PORT_D 
#define Pedestrian_button_pin 2

// Cars' LED Ports and Pins defines
#define Cars_green_LED_port   PORT_A
#define Cars_yellow_LED_port  PORT_A
#define Cars_red_LED_port     PORT_A
#define Cars_green_LED_pin     0
#define Cars_yellow_LED_pin    1
#define Cars_red_LED_pin       2
// Pedestrian's LED Ports and Pins defines
#define Pedestrian_green_LED_port   PORT_B
#define Pedestrian_yellow_LED_port  PORT_B
#define Pedestrian_red_LED_port     PORT_B
#define Pedestrian_green_LED_pin    0
#define Pedestrian_yellow_LED_pin   1
#define Pedestrian_red_LED_pin      2

// Pedestrian_mode status defines
#define OFF 0
#define ON 1

//Car_LEDs_state_While_pressed defines
#define Car_RED_ON 0
#define CAR_GREEN_ON_OR_Car_Yellow_Blink 1
// all function prototypes

void app_init(void);
void app_start(void);


#endif /* APP_H_ */