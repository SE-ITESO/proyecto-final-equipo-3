/*@File 	LCD_nokia.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the use for the LCD screen
*/

#ifndef LCD_NOKIA_H_
#define LCD_NOKIA_H_

#include "stdint.h"
#include "SPI.h"
#include "GPIO.h"
#include "LCD_nokia_images.h"
#include "Config.h"

#define MAP_SIZE_X 10
#define MAP_SIZE_Y 20
#define MAP_HOLD_SIZE 4
#define MAP_NEXT_SIZE 4

#define MAP_COL_0_MASK 0x0E
#define MAP_COL_1A_MASK 0XC0
#define MAP_COL_1B_MASK	0X01
#define MAP_COL_2_MASK	0X38
#define MAP_COL_3_MASK	0X07
#define MAP_COL_4_MASK	0XE0
#define MAP_COL_5_MASK	0X1C
#define MAP_COL_6A_MASK 0X80
#define MAP_COL_6B_MASK 0X03
#define MAP_COL_7_MASK  0X70
#define MAP_COL_8_MASK  0X0E
#define MAP_COL_9A_MASK 0XC0
#define MAP_COL_9B_MASK 0X01

#define MAP_offset_1 96
#define MAP_offset_2 180
#define MAP_offset_3 264
#define MAP_offset_4 348
#define MAP_offset_5 432

#define Next_COL_0_MASK		0X1C
#define Next_COL_1A_MASK	0X80
#define Next_COL_1B_MASK	0X03
#define Next_COL_2_MASK		0X70
#define Next_COL_3_MASK		0X0E

#define Next_offset_1	12
#define Next_offset_2	96

#define Hold_COL_0_MASK		0X1C
#define Hold_COL_1A_MASK	0X80
#define Hold_COL_1B_MASK	0X03
#define Hold_COL_2_MASK		0X70
#define Hold_COL_3_MASK		0X0E

#define Hold_offset_1	37
#define Hold_offset_2	121

#define SCREENW 84
#define SCREENH 48

#define SIZE_IN_BYTES 504
#define LCD_X 84
#define LCD_Y 48

#define LCD_DATA 1
#define LCD_CMD 0

#define LCD_0 0
#define LCD_1 1

#define DATA_OR_CMD_PIN pin5
#define RESET_PIN pin7

/*It configures the LCD*/
void LCD_nokia_init(void);
/*It writes a byte in the LCD memory. The place of writting is the last place that was indicated by LCDNokia_gotoXY. In the reset state
 * the initial place is x=0 y=0*/
void LCD_nokia_write_byte(uint8_t data_or_command, uint8_t data,uint8_t lcdScreen_selector);
/*it clears all the figures in the LCD*/
void LCD_nokia_clear(uint8_t lcdScreen_selector);
/*It is used to indicate the place for writing a new character in the LCD. The values that x can take are 0 to 84 and y can take values
 * from 0 to 5*/
void LCD_nokia_goto_xy(uint8_t x, uint8_t y,uint8_t lcdScreen_selector);
/*It allows to write a figure represented by constant array*/
void LCD_nokia_bitmap(uint8_t bitmap[],uint8_t lcdScreen_selector);
/*It write a character in the LCD*/
void LCD_nokia_send_char(uint8_t character,uint8_t lcdScreen_selector) ;
/*It write a string into the LCD*/
void LCD_nokia_send_string(uint8_t characters [],uint8_t lcdScreen_selector);
/*It displays the error message when a wdog reset occurs*/
void LCD_nokia_wdog();
/*Sets the loading screen for the LCD screen*/
void LCD_LoadingScreen();
/*Sets the menu screen when initializing the game*/
void LCD_MenuScreen();

void LCD_GameOverScreen();

void LCD_GameToLCD(game_info_t * gameInfo,uint8_t selector);





#endif /* LCD_NOKIA_H_ */
