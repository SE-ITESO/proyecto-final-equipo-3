/*@File 	PIT.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the Periodic Interrupt timer and
 *			its handler
 *
*/

#include "PIT.h"

//PIT_GetCurrentTimerCount(base, channel)

uint8_t g_wdog_refresh = 0;
volatile static void (*PIT_callback)() = 0;

void PIT1_IRQHandler (){
	g_wdog_refresh = 1;
	PIT_ClearStatusFlags(PIT,kPIT_Chnl_1,IRQ_CLEAN_MASK);
}

void PIT2_IRQHandler (){
	if(PIT_callback){
		PIT_callback();
	}
	PIT_ClearStatusFlags(PIT,kPIT_Chnl_2,IRQ_CLEAN_MASK);
}

void PIT_clear_wdog_refresh_f(){
	g_wdog_refresh = 0;

}

uint8_t PIT_get_wdog_refresh_f(){
	return g_wdog_refresh;
}

uint32_t PIT_GetCountValue(){
	return PIT_GetCurrentTimerCount(PIT, kPIT_Chnl_1);
}

void PIT_callback_init(void (*handler1)){
	PIT_callback = handler1;
}

void PIT_init(){
	uint32_t clock;
	pit_config_t pitConfig;
	clock = CLOCK_GetFreq(kCLOCK_BusClk);

	PIT_GetDefaultConfig(&pitConfig);	//Recupera la configuración default
	PIT_Init(PIT, &pitConfig);			//Aplica esa configuración en el PIT

	//PIT0 Frec muestreo
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(SAMPLE_PERIOD_US, clock)); //Indica el periodo para el canal 0 del PIT

	//PIT1 WDOG
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_1, USEC_TO_COUNT(WDOG_TIME_US, clock)); //Indica el periodo para el canal 0 del PIT
	PIT_EnableInterrupts(PIT, kPIT_Chnl_1, kPIT_TimerInterruptEnable);	//Habilita la interrupcion del pit
	EnableIRQ(PIT1_IRQn);	//Habilita la interrupcion de NVIC
	PIT_StartTimer(PIT, kPIT_Chnl_1);	//Habilita el timer del pit1

	//PIT2 INGAME_Time
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_2, USEC_TO_COUNT(INGAME_TIME_US, clock)); //Indica el periodo para el canal 0 del PIT
	PIT_EnableInterrupts(PIT, kPIT_Chnl_2, kPIT_TimerInterruptEnable);	//Habilita la interrupcion del pit
	EnableIRQ(PIT2_IRQn);	//Habilita la interrupcion de NVIC
}
