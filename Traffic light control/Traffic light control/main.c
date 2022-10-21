/*
 * Traffic light control.c
 *
 * Created: 9/29/2022 6:19:18 PM
 * Author :  Ali Mostafa ali Elsayed
 */ 

#include "Application/App.h"
//uint8_t Pedestrian_button_state = LOW ;

int main(void)
{
   
    app_init();
	app_start();
	
	
	
	/************************************************************************/
	/*             Testing the modules/Drivers                               */
	/************************************************************************/
	////DIO
	//uint8_t DIO_Driver_check_DIO_READ = 0 ;
	 //DIO_init(PORT_D,0,1);  // output
	  //DIO_init(PORT_D,1,0); //input
	 //DIO_write(PORT_D,0,1); 
	 //DIO_read(PORT_D ,1,&DIO_Driver_check_DIO_READ); 
	//// Timer
	 //timer0_init();
	 //delay500ms ();
	 //delay_5_sec ();
	// Led
	 //LED_init(PORT_D,0); //initialize LED
	 //LED_ON(PORT_D,0); //LED_ON
	 //LED_OFF(PORT_D,0); //LED_OFF
	 //LED_blink_for_N_sec(PORT_D,0,2); //LED_blink
	////return 0 ;

}





