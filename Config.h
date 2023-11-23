/*
 * Config.h
 *
 *  Created on: 10 nov 2023
 *      Author: CoolingCoder
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdint.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

typedef struct{
	uint8_t shape[4][4];
	uint8_t width;
	uint8_t height;
}tetromino_t;

typedef struct{
	uint8_t id;
	uint8_t gameOver_f;
	uint8_t board[BOARD_HEIGHT][BOARD_WIDTH];
	tetromino_t current_tetromino;
	tetromino_t next_tetromino;
	tetromino_t hold_tetromino;
	uint8_t canHold;
	uint8_t rowsToAdd;
	uint8_t counterToAddRows;
	uint8_t TetrominoX;
	uint8_t TetrominoY;
	uint8_t canMoveDown;
	uint8_t needsUpdate;
}game_info_t;

#endif /* CONFIG_H_ */
