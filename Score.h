/*@File 	Score.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the configuration and functions
 *			for the use of the score saved in memory
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
