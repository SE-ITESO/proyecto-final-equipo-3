/*
 * Game.c
 *
 * 		Created on: 9 nov 2023
 *      Author: CoolingCoder
 */

#include "Game.h"

state_t g_state;

uint8_t g_score1 = 0;
uint8_t g_score2 = 0;

void GameInit(){
	Clock_init();
	SPI_config();
	GPIO_init();
	LCD_nokia_init();
	LCD_LoadingScreen();
	I2C_init();
	//get music	from memory

	Watchdog_ResetDetection();
	PIT_init();
	DAC_init();
	DMA_init();
	//get score from memory
	Score_GetInitialScores(&g_score1,&g_score2);

	NVIC_init();
	GPIO_callback_init(Tetromino_HandlerForGPIO1,Tetromino_HandlerForGPIO2);
	PIT_callback_init(Tetromino_HandlerForPit);
	LCD_MenuScreen();
}

static void StartGame(){
	//reset status,boards and flags and show game
	Tetromino_ResetAndStart();
	//start music
	Music_PlayMusic();
	//start pit 2
	Tetromino_ResetFallData();
	PIT_StartTimer(PIT, kPIT_Chnl_2);	//Habilita el timer del pit1
}


void GameRunning(){
	switch(g_state){
		case GAME_OVER:
			if(0 == GPIO_get_pin_value(PLAYER1_PORT, PLAYER1_DOWN) && 0 == GPIO_get_pin_value(PLAYER2_PORT, PLAYER2_DOWN)){
				StartGame();
				GPIO_Enable_IRQ();
				g_state = PLAYING;
			}
			break;
		case PLAYING:
			if(1 == Tetromino_GetUpdateStatus(GAME1)){
				//UPDATE
				Tetromino_UpdateGame(GAME1);
				Tetromino_ClearUpdateStatus(GAME1);
			}
			if(1 == Tetromino_GetUpdateStatus(GAME2)){
				Tetromino_UpdateGame(GAME2);
				Tetromino_ClearUpdateStatus(GAME2);
			}
			if(1 == Tetromino_GetGeneralGameOverStatus()){
				GPIO_Disable_IRQ();
				Score_EndGameScore(&g_score1,&g_score2);
				//stop music
				Music_StopMusic();
				//stop pit 2
				PIT_StopTimer(PIT, kPIT_Chnl_2);	//Habilita el timer del pit1
				Tetromino_ResetFallData();
				g_state = GAME_OVER;
			}

			break;
	}
	if(1 == PIT_get_wdog_refresh_f()){
		Watchdog_Refresh();
		PIT_clear_wdog_refresh_f();
	}
}


