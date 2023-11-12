/*
 * Tetromino.c
 *
 *  Created on: 8 nov 2023
 *      Author: CoolingCoder
 */


#include "Tetromino.h"

game_info_t g_game1Info;
game_info_t g_game2Info;

periodic_fall_data_t g_fall_data = {
	.counter = 0,
	.module = 4,
	.twoMin_f = 0,
	.fourMin_f = 0,
};

static tetromino_t g_Tetrominos[7] = {
		{	//I shape
			.shape = {
					{1,1,1,1},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 4,
			.height = 1
		},
		{	//L shape
			.shape = {
					{0,0,1,0},
					{1,1,1,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 3,
			.height = 2
		},
		{	//Inverted L shape
			.shape = {
					{1,0,0,0},
					{1,1,1,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 3,
			.height = 2
		},
		{	//Z shape
			.shape = {
					{1,1,0,0},
					{0,1,1,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 3,
			.height = 2
		},
		{	//Inverted Z shape
			.shape = {
					{0,1,1,0},
					{1,1,0,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 3,
			.height = 2
		},
		{	//Square
			.shape = {
					{1,1,0,0},
					{1,1,0,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 2,
			.height = 2
		},
		{	//T shape
			.shape = {
					{0,1,0,0},
					{1,1,1,0},
					{0,0,0,0},
					{0,0,0,0}
			},
			.width = 3,
			.height = 2
		},
};

static tetromino_t g_empty_tetromino =  {
	    .shape = {  {0, 0, 0, 0},
	    			{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0} },
	    .width = 0,
	    .height = 0
};

static void Tetromino_CopyTetromino(tetromino_t * a, tetromino_t * b){
	static uint8_t i;
	static uint8_t j;
	a->height = b->height;
	a->width = b->width;
	for(i = 0; i<4;i++){
		for(j=0;j<4;j++){
			a->shape[i][j] = b->shape[i][j];
		}
	}
}

static void Tetromino_WriteTetromino(game_info_t * gameInfo){
    static uint8_t i;
	static uint8_t j;
	for (i = 0; i < gameInfo->current_tetromino.height; i++) {
		for (j = 0; j < gameInfo->current_tetromino.width; j++) {
			if (gameInfo->current_tetromino.shape[i][j]) {
				gameInfo->board[gameInfo->TetrominoY + i][gameInfo->TetrominoX + j] = 1; // Mark as part of the Tetromino on the board
			}
		}
	}
}

static void Tetromino_DeleteTetromino(game_info_t * gameInfo){
	static uint8_t i;
	static uint8_t j;
	for (i = 0; i < gameInfo->current_tetromino.height; i++) {
		for (j = 0; j < gameInfo->current_tetromino.width; j++) {
			if (gameInfo->current_tetromino.shape[i][j]) {
				gameInfo->board[gameInfo->TetrominoY + i][gameInfo->TetrominoX + j] = 0;
			}
		}
	}
}

static void Tetromino_ResetGameStatus(game_info_t * game){
	uint8_t i;
	uint8_t j;
	game->TetrominoY = 0;
	game->canHold = 1;
	game->canMoveDown = 1;
	game->gameOver_f = 0;

	for(i = 0; i < BOARD_HEIGHT; i++){
		for(j = 0; j < BOARD_WIDTH; j++){
			game->board[i][j] = 0;
		}
	}

}

void Tetromino_ResetAndStart(){
	 static uint32_t index;
	 Tetromino_ResetGameStatus(&g_game1Info);
	 Tetromino_ResetGameStatus(&g_game2Info);

	 Tetromino_CopyTetromino(&g_game1Info.hold_tetromino,&g_empty_tetromino);
	 Tetromino_CopyTetromino(&g_game2Info.hold_tetromino,&g_empty_tetromino);

	 index = PIT_GetCountValue() % 7;
	 Tetromino_CopyTetromino(&g_game1Info.current_tetromino,&g_Tetrominos[index]);
	 g_game1Info.TetrominoX = (BOARD_WIDTH - g_game1Info.current_tetromino.width) / 2;
	 index = PIT_GetCountValue() % 7;
	 Tetromino_CopyTetromino(&g_game1Info.next_tetromino,&g_Tetrominos[index]);
	 Tetromino_WriteTetromino(&g_game1Info);

	 index = PIT_GetCountValue() % 7;
	 Tetromino_CopyTetromino(&g_game2Info.current_tetromino,&g_Tetrominos[index]);
	 g_game2Info.TetrominoX = (BOARD_WIDTH - g_game2Info.current_tetromino.width) / 2;
	 index = PIT_GetCountValue() % 7;
	 Tetromino_CopyTetromino(&g_game2Info.next_tetromino,&g_Tetrominos[index]);
	 Tetromino_WriteTetromino(&g_game2Info);

	 //BITMAP Y MANDAR A LCD GAME 1
	 LCD_nokia_clear(LCD_0);
	 LCD_GameToLCD(&g_game1Info,LCD_0);
	 //BITMAP Y MANDAR A LCD GAME 2
	 LCD_nokia_clear(LCD_1);
	 LCD_GameToLCD(&g_game2Info,LCD_1);

}

static void Tetromino_nextTetromino(game_info_t * gameInfo){
	 static uint32_t index;

	 gameInfo->current_tetromino = gameInfo->next_tetromino;
	 index = PIT_GetCountValue() % 7;
	 Tetromino_CopyTetromino(&gameInfo->next_tetromino,&g_Tetrominos[index]);
	 gameInfo->TetrominoX = (BOARD_WIDTH - gameInfo->current_tetromino.width) / 2;
	 gameInfo->TetrominoY = 0;
	 gameInfo->canMoveDown = 1;
	 gameInfo->canHold = 1;

	 Tetromino_WriteTetromino(gameInfo);
}

void Tetromino_HoldTetromino(game_info_t * gameInfo){
	static tetromino_t temp_tetromino;
	if(1 == gameInfo->canHold){

		Tetromino_CopyTetromino(&temp_tetromino,&gameInfo->hold_tetromino);
		gameInfo->hold_tetromino = gameInfo->current_tetromino;
		gameInfo->current_tetromino = temp_tetromino;
		gameInfo->TetrominoX = (BOARD_WIDTH - gameInfo->current_tetromino.width) / 2;
		gameInfo->TetrominoY = 0; // Set the starting Y position
		gameInfo->canMoveDown = 1;

		if(0 == gameInfo->current_tetromino.width && 0 == gameInfo->current_tetromino.height)
			Tetromino_nextTetromino(gameInfo);
		else
			Tetromino_WriteTetromino(gameInfo);
		gameInfo->canHold = 0;

	}

}

void Tetromino_moveDown(game_info_t * gameInfo) {
    uint8_t newTetrominoY = gameInfo->TetrominoY + 1;
    static uint8_t i;
    static uint8_t j;
    if(gameInfo->canMoveDown){
		// Check for collisions with the bottom border or other blocks
		for (i = 0; i < gameInfo->current_tetromino.height; i++) {
			for (j = 0; j < gameInfo->current_tetromino.width; j++) {
				if (gameInfo->current_tetromino.shape[i][j] &&
						(newTetrominoY + i >= BOARD_HEIGHT ||
						(newTetrominoY + i < BOARD_HEIGHT &&
						 (gameInfo->board[newTetrominoY + i][gameInfo->TetrominoX + j] &&
								 (!(1 + i < gameInfo->current_tetromino.height) ||
						!gameInfo->current_tetromino.shape[i + 1][j])))))
				{
					// Collision detected
					gameInfo->canMoveDown = 0;
					gameInfo->needsUpdate = 1;
					return;
				}
			}
		}

		Tetromino_DeleteTetromino(gameInfo);

		// Update tetromino y position and ask for update
		gameInfo->TetrominoY = newTetrominoY;
		gameInfo->needsUpdate = 1;
		Tetromino_WriteTetromino(gameInfo);
    }
}

void Tetromino_moveLeft(game_info_t * gameInfo) {
    uint8_t newTetrominoX = gameInfo->TetrominoX - 1;
    static uint8_t i;
    static uint8_t j;
    // Check for collisions with the left border or other blocks
    for (i = 0; i < gameInfo->current_tetromino.height; i++) {
        for (j = 0; j < gameInfo->current_tetromino.width; j++) {
            if (gameInfo->current_tetromino.shape[i][j] && (newTetrominoX + j > 200 ||
                    (gameInfo->board[gameInfo->TetrominoY + i][newTetrominoX + j] &&
                    		(!(j - 1 < 200) ||
                     !gameInfo->current_tetromino.shape[i][j - 1])))){
                // Collision detected; stop moving
                return;
            }
        }
    }

    Tetromino_DeleteTetromino(gameInfo);

    // Update tetromino x position and ask for update
    gameInfo->TetrominoX = newTetrominoX;
    gameInfo->needsUpdate = 1;

    Tetromino_WriteTetromino(gameInfo);

}

void Tetromino_moveRight(game_info_t * gameInfo) {
    uint8_t newTetrominoX = gameInfo->TetrominoX + 1;
    static uint8_t i;
    static uint8_t j;

    // Check for collisions with the right border or other blocks
    for (i = 0; i < gameInfo->current_tetromino.height; i++) {
        for (j = 0; j < gameInfo->current_tetromino.width; j++) {
            if (gameInfo->current_tetromino.shape[i][j] && (newTetrominoX + j >= BOARD_WIDTH ||
                    (gameInfo->board[gameInfo->TetrominoY + i][newTetrominoX + j] &&
                    		(!(1 + j < gameInfo->current_tetromino.width) ||
                     !gameInfo->current_tetromino.shape[i][j + 1])))) {
                // Collision detected; stop moving
                return;
            }
        }
    }

    Tetromino_DeleteTetromino(gameInfo);

    // Update tetromino x position and ask for update
    gameInfo->TetrominoX = newTetrominoX;
    gameInfo->needsUpdate = 1;

    Tetromino_WriteTetromino(gameInfo);
}


// Function to rotate the Tetromino clockwise
void Tetromino_rotateClockwise(game_info_t * gameInfo) {
    static tetromino_t rotatedTetromino;
    static uint8_t i;
	static uint8_t j;
	Tetromino_CopyTetromino(&rotatedTetromino,&g_empty_tetromino);
    rotatedTetromino.width = gameInfo->current_tetromino.height;
    rotatedTetromino.height = gameInfo->current_tetromino.width;

    for (i = 0; i < gameInfo->current_tetromino.height; i++) {
        for (j = 0; j < gameInfo->current_tetromino.width; j++) {
            rotatedTetromino.shape[j][gameInfo->current_tetromino.height - 1 - i] = gameInfo->current_tetromino.shape[i][j];
        }
    }

    // Check for collisions with the borders or other blocks after rotation
    for (i = 0; i < rotatedTetromino.height; i++) {
        for (j = 0; j < rotatedTetromino.width; j++) {
            if (rotatedTetromino.shape[i][j] && (gameInfo->TetrominoX + j < 0 || gameInfo->TetrominoX + j >= BOARD_WIDTH || gameInfo->TetrominoY + i >= BOARD_HEIGHT ||
                    (gameInfo->board[gameInfo->TetrominoY + i][gameInfo->TetrominoX + j] && !rotatedTetromino.shape[i][j]))) {
                // Collision detected; cannot rotate
                return;
            }
        }
    }

    Tetromino_DeleteTetromino(gameInfo);

    Tetromino_CopyTetromino(&gameInfo->current_tetromino,&rotatedTetromino);
    gameInfo->needsUpdate = 1;


    Tetromino_WriteTetromino(gameInfo);
}

void Tetromino_UpdateOneGame(game_info_t * gameInfo){
	uint8_t linecomplete;
	uint8_t completedLines = 0;
	static uint8_t i;
	static uint8_t j;
	static uint8_t k;

	//if figure cant move down anymore
	if(0 == gameInfo->canMoveDown){
		// Clear completed rows if necessary (e.g., by checking the entire board for filled rows).
		for (i = BOARD_HEIGHT - 1; i >= 0 && i<BOARD_HEIGHT; i--) {
			linecomplete = 1;
			for (j = 0; j < BOARD_WIDTH; j++) {
				if (!gameInfo->board[i][j]) {
					linecomplete = 0;
					break;
				}
			}

			if (linecomplete) {
				// Clear the completed line
				for (k = i; k > 0; k--) {
					for (j = 0; j < BOARD_WIDTH; j++) {
						gameInfo->board[k][j] = gameInfo->board[k - 1][j];
					}
				}
				completedLines++;
				i++;
			}
		}

		//Check if game over
		if(0 == completedLines){	// si no se movio ninguna, revisar si no hubo un game over
			for (j = 0; j < gameInfo->current_tetromino.width; j++) {
			   if (gameInfo->current_tetromino.shape[0][j] && gameInfo->TetrominoY == 0) {
				   gameInfo->gameOver_f = 1;
			   }
			}
		}
		else{
			//SI SE TIENE FILAS POR AÑADIR, REDUCIR ESAS FILAS

			//MANDAR FILAS AL OTRO TAL
		}


		if(!gameInfo->gameOver_f)
			Tetromino_nextTetromino(gameInfo);
	}

	/*if(1 == addLines){	//Si pasó el tiempo para que sea necesario agregar lineas
		//recorrer lineas x cantidad arriba
		//poner x lineas con solo un bloque faltante. El bloque faltante se define por rand()
		addLines = 0;
	}*/



}

void Tetromino_UpdateGame(uint8_t selector) {
	if(1 == selector){
		Tetromino_UpdateOneGame(&g_game1Info);
		if(!g_game1Info.gameOver_f && !g_game2Info.gameOver_f){
			//BITMAP Y MANDAR A LCD
			LCD_GameToLCD(&g_game1Info,selector - 1);
		}
	}
	else{
		Tetromino_UpdateOneGame(&g_game2Info);
		if(!g_game1Info.gameOver_f && !g_game2Info.gameOver_f){
			//BITMAP Y MANDAR A LCD
			LCD_GameToLCD(&g_game2Info,selector - 1);
		}
	}
}


uint8_t Tetromino_GetUpdateStatus(uint8_t selector){
	if(1 == selector)
		return g_game1Info.needsUpdate;
	else
		return g_game2Info.needsUpdate;
}

void Tetromino_ClearUpdateStatus(uint8_t selector){
	if(1 == selector)
		g_game1Info.needsUpdate = 0;
	else
		g_game2Info.needsUpdate = 0;
}

uint8_t Tetromino_GetGameOverStatus(){
	return 1 == g_game1Info.gameOver_f || 1 == g_game2Info.gameOver_f;
}

void Tetromino_HandlerForGPIO1(port_t port,uint32_t flags){
	switch(flags){
		case P1_DOWN_MASK:	//DOWN
			Tetromino_moveDown(&g_game1Info);
			break;
		case P1_LEFT_MASK:	//LEFT
			Tetromino_moveLeft(&g_game1Info);
			break;
		case P1_RIGHT_MASK:	//RIGHT
			Tetromino_moveRight(&g_game1Info);
			break;
		case P1_ROTATE_MASK://ROTATE
			Tetromino_rotateClockwise(&g_game1Info);
			break;
		default:	//HOLD
			Tetromino_HoldTetromino(&g_game1Info);
			break;
	}
}

void Tetromino_HandlerForGPIO2(port_t port,uint32_t flags){
	switch(flags){
		case P2_DOWN_MASK:	//DOWN
			Tetromino_moveDown(&g_game2Info);
			break;
		case P2_LEFT_MASK:	//LEFT
			Tetromino_moveLeft(&g_game2Info);
			break;
		case P2_RIGHT_MASK:	//RIGHT
			Tetromino_moveRight(&g_game2Info);
			break;
		case P2_ROTATE_MASK://ROTATE
			Tetromino_rotateClockwise(&g_game2Info);
			break;
		default:	//HOLD
			Tetromino_HoldTetromino(&g_game2Info);
			break;
	}
}

void Tetromino_ResetFallData(){
	g_fall_data.counter = 0;
	g_fall_data.module = 4;
	g_fall_data.twoMin_f = 0;
	g_fall_data.fourMin_f = 0;
}

void Tetromino_HandlerForPit(){
	g_fall_data.counter++;
	if(0 == g_fall_data.counter % g_fall_data.module){	//1 seg
		Tetromino_moveDown(&g_game1Info);
		Tetromino_moveDown(&g_game2Info);
	}
	if(0 == g_fall_data.twoMin_f){
		if(0 == g_fall_data.counter % 480){//si ya pasaron 2 min
			g_fall_data.twoMin_f = 1;
			g_fall_data.module = 2;
		}
	}
	else if(0 == g_fall_data.fourMin_f){
		if(0 == g_fall_data.counter % 960){//si ya pasaron 2 min
			g_fall_data.fourMin_f = 1;
			g_fall_data.module = 1;
		}
	}
}
