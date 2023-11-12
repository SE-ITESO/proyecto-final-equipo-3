/*@File 	Display.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros and data types
 *			for the use of the WDOG timer
*/

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "fsl_wdog.h"
#include "fsl_rcm.h"
#include "LCD_nokia.h"

#define WDOG_CONFIG_COUNT (256U)
#define WDOG_NORMAL_TIMEOUT_VAL 3000

uint8_t Watchdog_ResetDetection();
void Watchdog_Refresh();
void Watchdog_init(uint16_t wdog_reset_count);

#endif /* WATCHDOG_H_ */
