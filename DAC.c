/*@File 	DAC.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the Digital to Analog Converter
 *			configuration and functions for its output
*/

#include "DAC.h"


void DAC_init(){
	dac_config_t dacConfigStruct;

	DAC_GetDefaultConfig(&dacConfigStruct);	//Recupera la configuración default
	DAC_Init(DAC0, &dacConfigStruct);		//Aplica esa configuración al DAC0
	DAC_Enable(DAC0, true);             //Inicializa el DAC0
	DAC_SetBufferReadPointer(DAC0, DAC_BUFFER_0);	//Indica el valor del buffer donde leera el dato
	DAC_SetBufferValue(DAC0, DAC_BUFFER_0, 0);
}

