/*@File 	Game.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros and data types
 *			for the use of the Game module and the main control area of the proyect
*/

#ifndef GAME_H_
#define GAME_H_

#include "Clock.h"
#include "SPI.h"
#include "GPIO.h"
#include "LCD_nokia.h"
#include "I2C.h"
#include "Watchdog.h"
#include "PIT.h"
#include "DAC.h"
#include "DMA.h"
#include "NVIC.h"
#include "Tetromino.h"
#include "Score.h"

#define PLAYER1_PORT B
#define PLAYER1_DOWN pin19

#define PLAYER2_PORT C
#define PLAYER2_DOWN pin1

#define GAME1 1
#define GAME2 2

typedef enum{
	LOADING,
	GAME_OVER,
	PLAYING
}state_t;



void GameInit();
void GameRunning();


#endif /* GAME_H_ */
