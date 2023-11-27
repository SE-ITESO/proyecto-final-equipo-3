/*@File 	Sounds.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting macro for the functions for the
 *@Brief	sound reproduction flow for the main project
*/

#ifndef MUSIC_H_
#define MUSIC_H_


#include "DMA.h"
#include "PIT.h"
#include "I2C.h"

#define MUSIC_LENGHT 0x12C3A
#define MUSIC_BASEADDR 64

void Music_GetMusic();

void Music_PlayMusic();

void Music_StopMusic();


#endif /* MUSIC_H_ */
