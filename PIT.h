/*@File 	PIT.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros
 *			for the Periodic Interrupt timer
 *
*/

#ifndef PIT_H_
#define PIT_H_

#include <stdint.h>
#include "fsl_pit.h"
#include "Watchdog.h"

#define IRQ_CLEAN_MASK 1

#define WDOG_TIME_US 			1500000 //1s para WDOG
#define SAMPLE_PERIOD_US	 	333 //16k Frecuencia de muestreo
#define INGAME_TIME_US	 		200000

void PIT1_IRQHandler ();

void PIT_init();
void PIT_clear_wdog_refresh_f();
uint8_t PIT_get_wdog_refresh_f();
void PIT_callback_init(void (*handler1));

uint32_t PIT_GetCountValue();

#endif /* PIT_H_ */
