/*@File 	SPI.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting an init function for the SPI
*/
#include "SPI.h"


void SPI_config(void)
{
	/**Funcion para configurar el modulo spi con sus respectivos CTARs**/
	uint32_t srcClock_Hz;
	dspi_master_config_t masterConfig;
	
	srcClock_Hz = CLOCK_GetFreq(DSPI0_CLK_SRC);
	/*Se configura el CTAR0 para el display1*/
	masterConfig.whichCtar 									= kDSPI_Ctar0;
	masterConfig.ctarConfig.baudRate 						= TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.bitsPerFrame					= 8U;
	masterConfig.ctarConfig.cpol							= kDSPI_ClockPolarityActiveHigh;
	masterConfig.ctarConfig.cpha							= kDSPI_ClockPhaseFirstEdge;
	masterConfig.ctarConfig.direction 						= kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec			= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec		= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec	= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;

	masterConfig.whichPcs 			= kDSPI_Pcs0;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK		= false;
	masterConfig.enableRxFifoOverWrite 		= false;
	masterConfig.enableModifiedTimingFormat	= false;
	masterConfig.samplePoint 				= kDSPI_SckToSin0Clock;


	DSPI_MasterInit(SPI0, &masterConfig,srcClock_Hz);

	/*Se configura el CTAR1 para el display2*/
	masterConfig.whichCtar 									= kDSPI_Ctar1;
	masterConfig.ctarConfig.baudRate 						= TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.bitsPerFrame					= 8U;
	masterConfig.ctarConfig.cpol							= kDSPI_ClockPolarityActiveHigh;
	masterConfig.ctarConfig.cpha							= kDSPI_ClockPhaseFirstEdge;
	masterConfig.ctarConfig.direction 						= kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec			= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec		= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec	= 1000000000U/ TRANSFER_BAUDRATE_DISPLAY;

	masterConfig.whichPcs 			= kDSPI_Pcs1;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK		= false;
	masterConfig.enableRxFifoOverWrite 		= false;
	masterConfig.enableModifiedTimingFormat	= false;
	masterConfig.samplePoint 				= kDSPI_SckToSin0Clock;


	DSPI_MasterInit(SPI0, &masterConfig,srcClock_Hz);

}
