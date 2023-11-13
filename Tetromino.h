/*
 * Tetromino.h
 *
 *  Created on: 8 nov 2023
 *      Author: CoolingCoder
 */

#ifndef TETROMINO_H_
#define TETROMINO_H_


#include "GPIO.h"
#include "PIT.h"
#include "Game.h"
#include "LCD_nokia.h"
#include "Config.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define NUMBER_OF_TETROMINOS 7
#define INVALID_NUMBER 200

#define TWO_MIN_MARK 600
#define FOUR_MIN_MARK 1200


#define P1_DOWN_MASK 0x80000
#define P1_LEFT_MASK 0x40000
#define P1_RIGHT_MASK 0x200
#define P1_ROTATE_MASK 0x800000

#define P2_DOWN_MASK 2
#define P2_LEFT_MASK 0x100
#define P2_RIGHT_MASK 0x200
#define P2_ROTATE_MASK 1

typedef struct{
	uint16_t counter;
	uint8_t module;
	uint8_t twoMin_f;
	uint8_t fourMin_f;
}periodic_fall_data_t;

void Tetromino_ResetAndStart();
void Tetromino_HandlerForGPIO1(port_t port,uint32_t flags);
void Tetromino_HandlerForGPIO2(port_t port,uint32_t flags);
void Tetromino_HandlerForPit();
void Tetromino_ResetFallData();
uint8_t Tetromino_GetGeneralGameOverStatus();
uint8_t Tetromino_GetGameOverStatus(uint8_t selector);
uint8_t Tetromino_GetUpdateStatus(uint8_t selector);
void Tetromino_ClearUpdateStatus(uint8_t selector);
void Tetromino_UpdateGame(uint8_t selector);

#endif /* TETROMINO_H_ */
