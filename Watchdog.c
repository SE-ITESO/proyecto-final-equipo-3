/*@File 	Watchdog.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of controlling the Watchdog timer
 *@Brief	in order to ensure correct program flow
*/

#include "Watchdog.h"

static uint16_t Watchdog_GetResetCount()
{
	uint16_t wdog_reset_count = 0;

	if (!(RCM_GetPreviousResetSources(RCM) & kRCM_SourceWdog))
	{
		WDOG_ClearResetCount(WDOG);
	}
	wdog_reset_count = WDOG_GetResetCount(WDOG);

	return wdog_reset_count;
}


static void WaitWctClose(WDOG_Type *base)
{
    for (uint32_t i = 0; i < WDOG_CONFIG_COUNT; i++)
    {
        (void)base->RSTCNT;
    }
}

void Watchdog_init(uint16_t wdog_reset_count){
    static wdog_config_t config;
	WDOG_GetDefaultConfig(&config);
	config.timeoutValue = WDOG_NORMAL_TIMEOUT_VAL;
	WDOG_Init(WDOG, &config);
	WaitWctClose(WDOG);
}

uint8_t Watchdog_ResetDetection(){
	static uint8_t wdog_reset_count = 0;
	wdog_reset_count = Watchdog_GetResetCount();
	if( 1 == wdog_reset_count)
	{
		LCD_nokia_wdog();
		while(1)
		{
		}
	}
	Watchdog_init(wdog_reset_count);
	return wdog_reset_count;
}


void Watchdog_Refresh(){
	WDOG_Refresh(WDOG);
}
