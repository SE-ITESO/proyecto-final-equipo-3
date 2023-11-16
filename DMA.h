/*@File 	DMA.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros and data types
 *			for the use of the Direct Memory Access
*/

#ifndef DMA_H_
#define DMA_H_

#include "fsl_dmamux.h"
#include "fsl_edma.h"
#include "Sounds.h"
#include "PIT.h"
#include "DAC.h"

#define DAC0_BUFFER_RESET 0
#define TCD_QUEUE_SIZE      1U
#define DMA_AWLWAYS_ENABLE (58u)
#define DMA_CHN_0 0
#define DAC0_L_ADDR (uint32_t *) 0x400CC000

void DMA_init();
void DMA_SendSound(uint16_t * source, uint16_t size);

#endif /* DMA_H_ */
