/*@File 	Sounds.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting macro for the functions for the
 *@Brief	sound reproduction flow for the main project
*/

#ifndef SOUNDS_H_
#define SOUNDS_H_


#include "DMA.h"
#include "GPIO.h"
#include "LCD_nokia.h"

#define SOUNDS 9
#define BUFFER_LENGTH 20
#define BUFFER_LAST_VALUE 19

#define KICK_ADDR 0x2C000
#define SNARE_ADDR 0x37000
#define BONGO_ADDR 0x4000
#define HITHAT_ADDR 0x25000
#define GUIRO_ADDR 	0x16000
#define RIMSHOT_ADDR 0x31000
#define TAMBOR_ADDR 0x39000
#define CYNBAL_ADDR 0xE000
#define COWBELL_ADDR 0xC000

#define KICK_LENGHT_BYTES 6704
#define SNARE_LENGHT_BYTES 3561
#define BONGO_LENGHT_BYTES 2067
#define HITHAT_LENGHT_BYTES 2410
#define GUIRO_LENGHT_BYTES 7067
#define RIMSHOT_LENGHT_BYTES 808
#define TAMBOR_LENGHT_BYTES 4650
#define CYNBAL_LENGHT_BYTES 10075
#define COWBELL_LENGHT_BYTES 2557

#define KICK_LENGHT_FINAL 3352
#define SNARE_LENGHT_FINAL 1781
#define BONGO_LENGHT_FINAL 1034
#define HITHAT_LENGHT_FINAL 1205
#define GUIRO_LENGHT_FINAL 3534
#define RIMSHOT_LENGHT_FINAL 404
#define TAMBOR_LENGHT_FINAL 2325
#define CYNBAL_LENGHT_FINAL 5038
#define COWBELL_LENGHT_FINAL 1279

typedef struct{
	uint8_t kick[KICK_LENGHT_BYTES];
	uint8_t snare[SNARE_LENGHT_BYTES];
	uint8_t bongo[BONGO_LENGHT_BYTES];
	uint8_t hithat[HITHAT_LENGHT_BYTES];
	uint8_t guiro[GUIRO_LENGHT_BYTES];
	uint8_t rimshot[RIMSHOT_LENGHT_BYTES];
	uint8_t tambor[TAMBOR_LENGHT_BYTES];
	uint8_t cynbal[CYNBAL_LENGHT_BYTES];
	uint8_t cowbell[COWBELL_LENGHT_BYTES];
}raw_sounds_t;

typedef struct{
	uint16_t kick[KICK_LENGHT_FINAL];
	uint16_t snare[SNARE_LENGHT_FINAL];
	uint16_t bongo[BONGO_LENGHT_FINAL];
	uint16_t hithat[HITHAT_LENGHT_FINAL];
	uint16_t guiro[GUIRO_LENGHT_FINAL];
	uint16_t rimshot[RIMSHOT_LENGHT_FINAL];
	uint16_t tambor[TAMBOR_LENGHT_FINAL];
	uint16_t cynbal[CYNBAL_LENGHT_FINAL];
	uint16_t cowbell[COWBELL_LENGHT_FINAL];
}processed_sounds_t;

typedef enum{
	k = 'K',
	s = 'S',
	b = 'B',
	h = 'H',
	g = 'G',
	r = 'R',
	t = 'T',
	c = 'C',
	w = 'W'
}sounds_char_t;

void Sounds_ProcessSounds();

void Sounds_stopPlaying();
void Sounds_GetSounds();
void Sounds_ClearSoundBuffer();
void Sounds_ClearIndex();
void Sounds_PlayNext();

void Sounds_GpioCallback(port_t port,uint32_t flags);

uint8_t Sounds_GetCounter();

void Sounds_SequenceOn();
void Sounds_SequenceOff();

#endif /* SOUNDS_H_ */
