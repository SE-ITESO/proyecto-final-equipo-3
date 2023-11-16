/*@File 	Clock.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the
 *			configuration function for the External Clock
*/

#include "Clock.h"


void Clock_init(){
	//Se define la MCG PLL configuration
	const static mcg_pll_config_t pll0Config = {
			.enableMode = MCG_PLL_DISABLE,
			.prdiv = PLL_PRDIV,
			.vdiv  = PLL_VDIV,
	};

	const static osc_config_t osc_config = {
			.freq = OSC_FREQ,
			.capLoad = (OSC_CAP0P),
			.workMode = kOSC_ModeExt,
			.oscerConfig = {
					.enableMode = kOSC_ErClkEnable,
			}
	};

	CLOCK_SetSimSafeDivs();

	CLOCK_InitOsc0(&osc_config);
	CLOCK_SetXtal0Freq(osc_config.freq);	//turn xtal0 on

	CLOCK_BootToPeeMode(kMCG_OscselOsc, kMCG_PllClkSelPll0, &pll0Config); //config pll and config pee mode for 120Mhz SCK

}
