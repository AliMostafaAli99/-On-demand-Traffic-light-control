/*
 * dio.h
 *
 * Created: 9/29/2022 8:14:43 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Register.h"
// all internal driver typedefs

typedef enum EN_DIO_error_t
   {
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_DIRECTION,
	DIO_WRONG_VALUE,
	DIO_OK
	} EN_DIO_error_t ;



// all driver macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction defines
#define INPUT 0
#define OUTPUT 1

// value defines
#define LOW 0
#define HIGH 1


// all function prototypes

 EN_DIO_error_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction); //initialize dio direction
 
 EN_DIO_error_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value); //write data to dio
 
 EN_DIO_error_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value); //read dio
 



#endif /* DIO_H_ */