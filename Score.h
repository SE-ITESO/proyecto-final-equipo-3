/*
 * Score.h
 *
 *  Created on: 26 nov 2023
 *      Author: CoolingCoder
 */

#ifndef SCORE_H_
#define SCORE_H_

#include "I2C.h"
#include "Tetromino.h"

#define SCORES_SIZE 	2
#define SCORES_BASEADDR 0


void Score_GetInitialScores(uint8_t * score1, uint8_t * score2);
void Score_EndGameScore(uint8_t * score1, uint8_t * score2);

#endif /* SCORE_H_ */
