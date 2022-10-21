/*
 * interrupt.h
 *
 * Created: 10/1/2022 2:37:36 PM
 *  Author: Ali Mostafa ali Elsayed
 */ 
 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../Utilities/Register.h"

/************************************************************************/
/*                          Interrupt vectors                        */
/************************************************************************/

/* External Interrupt vectors*/

/* External Interrupt Request 0  */

#define EXT_INT_0 __vector_1




/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")


/* ISR definition */
#define  ISR(INT_VECT)void INT_VECT (void) __attribute__ ((signal,used)) ; \
 void INT_VECT (void)

 
 
#endif /* INTERRUPT_H_ */
