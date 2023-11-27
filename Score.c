/*
 * Score.c
 *
 *  Created on: 26 nov 2023
 *      Author: CoolingCoder
 */


#include "Score.h"

void Score_GetInitialScores(uint8_t * score1, uint8_t * score2){
	static uint8_t scores[2];
	static status_t i2c_status;
	//uint8_t * data,uint16_t sub_address,uint8_t data_size_for_I2C
	i2c_status = I2C_read(scores,SCORES_BASEADDR,SCORES_SIZE);
	if(0 != i2c_status)
		while(1){}
	*score1 = scores[0];
	*score2 = scores[1];
}

void Score_EndGameScore(uint8_t * score1, uint8_t * score2){
	static uint8_t scores[2];
	static status_t i2c_status;
	//check who lost and register it
	if(1 == Tetromino_GetGameOverStatus(GAME1)){
		*score2 += 1;
		LCD_GameOverScreenWinner(GAME2,*score2);
		LCD_GameOverScreenLoser(GAME1,*score1);
	}
	else{
		*score2 += 1;
		LCD_GameOverScreenWinner(GAME1,*score1);
		LCD_GameOverScreenLoser(GAME2,*score2);
	}
	//save scores to memory
	scores[0] = *score1;
	scores[1] = *score2;
	//uint8_t * data,uint16_t sub_address,uint8_t data_size_for_I2C
	i2c_status = I2C_write(scores,SCORES_BASEADDR,SCORES_SIZE);
	if(0 != i2c_status)
		while(1){}
}
