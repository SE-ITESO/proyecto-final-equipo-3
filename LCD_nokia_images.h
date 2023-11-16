/*@File 	LCD_nokia_images.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the function to retrieve the bitmap for a Band's Logo
*/
#ifndef LCD_NOKIA_IMAGES_H_
#define LCD_NOKIA_IMAGES_H_

#include "stdint.h"
#define LCD_BITMAP_SIZE 504

void LCD_image_GetMainMenu(uint8_t * picture);
void LCD_image_GetArena(uint8_t * picture);
void LCD_image_GetLoadingImage(uint8_t * picture);

void LCD_image_GetWinnerImage(uint8_t * picture);
void LCD_image_GetLoserImage(uint8_t * picture);

#endif /* LCD_NOKIA_IMAGES_H_ */
