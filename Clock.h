/*@File 	Clock.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the macro definition for the
 *			configuration function for the External Clock
*/


#ifndef CLOCK_H_
#define CLOCK_H_

#include "fsl_clock.h"

#define OSC_FREQ 50000000
#define MCG_PLL_DISABLE 0
#define OSC_CAP0P 0
#define PLL_PRDIV 0xeU //DIVIDE BY 15
#define PLL_VDIV 0x8U //MULTIPLY BY 32

void Clock_init();

#endif /* CLOCK_H_ */
