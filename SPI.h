/*@File 	SPI.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining an init function for the SPI
*/
#ifndef SPI_H_
#define SPI_H_


#include "Clock.h"
#include "fsl_dspi.h"

#define TRANSFER_BAUDRATE_DISPLAY 1000000U //1Mhz


void SPI_config(void);

#endif /* SPI_H_ */
