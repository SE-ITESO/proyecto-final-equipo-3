/*@File 	main.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is the main file of the implementation,
 *@Brief	its then highest level or hierarchy responsible for the program
 *@Brief	flow and all the initializations needed for the game
*/

#include "Game.h"

int main(void) {

  	GameInit();

    while(1) {

    	GameRunning();
    }
    return 0 ;
}
