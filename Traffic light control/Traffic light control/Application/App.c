/*
 * App.c
 *
 * Created: 9/29/2022 11:08:39 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 
// include .h
#include "App.h"

// global variables
 uint8_t CAR_Red_LED_STate = LOW ;
 uint8_t CAR_yello_LED_STate = LOW ;
 uint8_t CAR_Green_LED_STate = LOW ;
 uint8_t Car_LEDs_state_While_pressed ;
 uint8_t Pedestrian_button_state = LOW ;


// function definitions

void app_init(void)
{
	// initialize Cars' LEDs
	LED_init(Cars_green_LED_port,Cars_green_LED_pin);
	LED_init(Cars_yellow_LED_port,Cars_yellow_LED_pin);
	LED_init(Cars_red_LED_port,Cars_red_LED_pin);
	
	// initialize Pedestrian's LEDs
	LED_init(Pedestrian_green_LED_port,Pedestrian_green_LED_pin);
	LED_init(Pedestrian_yellow_LED_port,Pedestrian_yellow_LED_pin);
	LED_init(Pedestrian_red_LED_port,Pedestrian_red_LED_pin);
	
	// initialize Pedestrian's button
	button_init(Pedestrian_button_port,Pedestrian_button_pin);
	
	// initialize timer
	timer0_init();
	
	
	/* Enable Global Interrupt, Set the I-bit in status register to 1 */
	sei();
	/*choose the external Interrupt sense - sense on rising edge */
	MCUCR |= (1<<0) | (1<<1);
	/* Enable external Interrupt 0 - INT0 */
	GICR |= (1<<6);
}

void app_start(void)
{
	
	while (1)
	{
		// all logic repetitive
		
		switch (Pedestrian_mode)
		{
		case OFF:
		
		// turn on  Cars' Green LED
		LED_ON(Cars_green_LED_port,Cars_green_LED_pin);
		CAR_Green_LED_STate = ON;
		
		//delay_5_sec
		delay_5_sec();
		
		// Prevent execution of the rest of "case off) in the switch function
		if(Pedestrian_mode == ON) break;
		
		//turn off Cars' Green LED
		LED_OFF(Cars_green_LED_port,Cars_green_LED_pin);
		CAR_Green_LED_STate = OFF;
		
		// blink Cars' yellow LED 5 sec
		CAR_yello_LED_STate = ON;
		LED_blink_for_N_sec(Cars_yellow_LED_port,Cars_yellow_LED_pin,5);
		CAR_yello_LED_STate = OFF;
		
		// turn on  Cars' REd LED
		LED_ON(Cars_red_LED_port,Cars_red_LED_pin);
		CAR_Red_LED_STate = ON;
		
		//delay_5_sec
		delay_5_sec();
		
		// Prevent execution of the rest of "case off) in the switch function
		if(Pedestrian_mode == ON) break;
		
		//turn off Cars' REd LED
		LED_OFF(Cars_red_LED_port,Cars_red_LED_pin);
		CAR_Red_LED_STate = OFF;
		
		// blink Cars' yellow LED 5 sec
		CAR_yello_LED_STate = ON;
		LED_blink_for_N_sec(Cars_yellow_LED_port,Cars_yellow_LED_pin,5);
		CAR_yello_LED_STate = OFF;
		
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		case ON :
			
		// change the state of pedestrian mode to off because the delay functions have instruction (break;) wheen Pedestrian_mode = ON
		Pedestrian_mode = OFF ;
		
		
			
		if (Car_LEDs_state_While_pressed == CAR_GREEN_ON_OR_Car_Yellow_Blink)
		{
			// Turn ON Pedestrian Red LED and Both yellow LED blink for 5 sec
			LED_ON(Pedestrian_red_LED_port,Pedestrian_red_LED_pin);
			LED_both_blink_for_N_sec(Pedestrian_yellow_LED_port,Pedestrian_yellow_LED_pin,5,Cars_yellow_LED_port,Cars_yellow_LED_pin);
				
			// Turn OFF: Pedestrian Red LED & Car Green LED
			// Turn ON : Pedestrian Green LED & Car RED LED
			LED_OFF(Pedestrian_red_LED_port,Pedestrian_red_LED_pin);
			LED_OFF(Cars_green_LED_port,Cars_green_LED_pin);
			LED_ON(Pedestrian_green_LED_port,Pedestrian_green_LED_pin);
			LED_ON(Cars_red_LED_port,Cars_red_LED_pin);
		}
			
		else if(Car_LEDs_state_While_pressed == Car_RED_ON)
		{
			// Turn ON : Pedestrian Green LED & Car RED LED remains ON
			LED_ON(Pedestrian_green_LED_port,Pedestrian_green_LED_pin);
		}
			
			
		//delay_5_sec
		delay_5_sec();
			
		// Turn OFF Car RED LED 
		// Pedestrian Green LED still on and blink both yellow LED for 5 sec
		LED_OFF(Cars_red_LED_port,Cars_red_LED_pin);
		LED_ON(Pedestrian_green_LED_port,Pedestrian_green_LED_pin);
		LED_both_blink_for_N_sec(Pedestrian_yellow_LED_port,Pedestrian_yellow_LED_pin,5,Cars_yellow_LED_port,Cars_yellow_LED_pin);
			
			
			
		//turn off : Pedestrian's  Green LED & Both red LEDs 
		LED_OFF(Pedestrian_green_LED_port,Pedestrian_green_LED_pin);
		LED_OFF(Cars_red_LED_port,Cars_red_LED_pin);
		LED_OFF(Pedestrian_red_LED_port,Pedestrian_red_LED_pin);
			
		// turn on  Cars' Green LED
		LED_ON(Cars_green_LED_port,Cars_green_LED_pin);
			
		// change the state of pedestrian mode to off 
		Pedestrian_mode = OFF ;
			
		break;
		}
		
	}
}

ISR(EXT_INT_0)
{
	
	// change the state of pedestrian mode to ON
	Pedestrian_mode = ON ;
	
	// check in which state the pedestrian button pressed
	if (CAR_Green_LED_STate== ON|| CAR_yello_LED_STate == ON)
	{
		
		Car_LEDs_state_While_pressed = CAR_GREEN_ON_OR_Car_Yellow_Blink;
		
		
	}
	else if (CAR_Red_LED_STate == ON )
	{
		Car_LEDs_state_While_pressed = Car_RED_ON;
		
	}
}