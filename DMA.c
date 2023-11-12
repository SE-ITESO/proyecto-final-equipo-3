/*@File 	DMA.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the configuration and functions
 *			for the use of the Direct Memory Access
*/

#include "DMA.h"

AT_QUICKACCESS_SECTION_DATA_ALIGN(edma_tcd_t tcdMemoryPoolPtr[TCD_QUEUE_SIZE + 1], sizeof(edma_tcd_t));

void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds){

}

void DMA_init(){
	static edma_handle_t EDMA_Handle;
	static edma_config_t userConfig;

	DMAMUX_Init(DMAMUX0);
	DMAMUX_SetSource(DMAMUX0, DMA_CHN_0, DMA_AWLWAYS_ENABLE);
	DMAMUX_EnablePeriodTrigger(DMAMUX0, DMA_CHN_0);
	DMAMUX_EnableChannel(DMAMUX0, DMA_CHN_0);

	EDMA_GetDefaultConfig(&userConfig);
	EDMA_Init(DMA0, &userConfig);
	EDMA_CreateHandle(&EDMA_Handle, DMA0, DMA_CHN_0);
	EDMA_SetCallback(&EDMA_Handle, EDMA_Callback, NULL);
	EDMA_ResetChannel(EDMA_Handle.base, EDMA_Handle.channel);
}

void DMA_SendSound(uint16_t * source, uint16_t size){
	static edma_transfer_config_t transferConfig;
	EDMA_PrepareTransferConfig(&transferConfig,
			   source,
			   2,
			   2, /* source offset */
			   DAC0_L_ADDR,	//Destiny Address
			   2,
			   0,               /* dest offset */
			   2,             /* minor loop bytes: 8*/
			   size*2); /* major loop counts : 4 */


   EDMA_TcdSetMajorOffsetConfig(
					   tcdMemoryPoolPtr, //param tcd A point to the TCD structure.
					   -(size*2), //* param sourceOffset source address offset.
					   0);//destOffset destination address offset.

   EDMA_TcdSetTransferConfig(tcdMemoryPoolPtr, &transferConfig, NULL);

   EDMA_TcdEnableInterrupts(&tcdMemoryPoolPtr[0], kEDMA_MajorInterruptEnable);
   EDMA_TcdEnableAutoStopRequest(&tcdMemoryPoolPtr[0], true);
   EDMA_InstallTCD(DMA0, DMA_CHN_0, &tcdMemoryPoolPtr[0]);
   EDMA_EnableChannelRequest(DMA0, DMA_CHN_0);
   PIT_StartTimer(PIT, kPIT_Chnl_0);
}
