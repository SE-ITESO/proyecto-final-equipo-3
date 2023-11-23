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

#define LCD_Contrast 0xBF
#define LCD_Temp_Coef 0x04
#define LCD_BiasMode 0x14
#define LCD_DispControl 0x0c
#define LCD_PreDispControl 0x20
#define LCD_Ext_comm 0x21


#define Bar_Mask_16 432
#define Bar_Mask_15 436
#define Bar_Mask_14 440
#define Bar_Mask_13 444
#define Bar_Mask_12 447
#define Bar_Mask_11 451
#define Bar_Mask_10 455
#define Bar_Mask_9 459
#define Bar_Mask_8 462
#define Bar_Mask_7 466
#define Bar_Mask_6 470
#define Bar_Mask_5 474
#define Bar_Mask_4 477
#define Bar_Mask_3 481
#define Bar_Mask_2 485
#define Bar_Mask_1 489
#define Bar_Mask_limit 492
#define Bar_Mask_LCD 0XE0

#define Score_Unit_9_val_1 0x60
#define Score_Unit_9_val_2 0x90
#define Score_Unit_9_val_3 0x90
#define Score_Unit_9_val_4 0x70
#define Score_Unit_9_val_5 0x10
#define Score_Unit_9_val_6 0x10
#define Score_Unit_9_val_7 0x10
#define Score_Unit_9_val_8 0x10

#define Score_Unit_8_val_1 0x60
#define Score_Unit_8_val_2 0x90
#define Score_Unit_8_val_3 0x90
#define Score_Unit_8_val_4 0x60
#define Score_Unit_8_val_5 0x90
#define Score_Unit_8_val_6 0x90
#define Score_Unit_8_val_7 0x90
#define Score_Unit_8_val_8 0x90

#define Score_Unit_7_val_1 0xf0
#define Score_Unit_7_val_2 0x10
#define Score_Unit_7_val_3 0x10
#define Score_Unit_7_val_4 0x70
#define Score_Unit_7_val_5 0x10
#define Score_Unit_7_val_6 0x10
#define Score_Unit_7_val_7 0x10
#define Score_Unit_7_val_8 0x10

#define Score_Unit_6_val_1 0x70
#define Score_Unit_6_val_2 0x80
#define Score_Unit_6_val_3 0x80
#define Score_Unit_6_val_4 0x60
#define Score_Unit_6_val_5 0x90
#define Score_Unit_6_val_6 0x90
#define Score_Unit_6_val_7 0x90
#define Score_Unit_6_val_8 0x60

#define Score_Unit_5_val_1 0xf0
#define Score_Unit_5_val_2 0x80
#define Score_Unit_5_val_3 0x80
#define Score_Unit_5_val_4 0xe0
#define Score_Unit_5_val_5 0x10
#define Score_Unit_5_val_6 0x10
#define Score_Unit_5_val_7 0x10
#define Score_Unit_5_val_8 0xe0

#define Score_Unit_4_val_1 0x90
#define Score_Unit_4_val_2 0x90
#define Score_Unit_4_val_3 0x90
#define Score_Unit_4_val_4 0x70
#define Score_Unit_4_val_5 0x10
#define Score_Unit_4_val_6 0x10
#define Score_Unit_4_val_7 0x10
#define Score_Unit_4_val_8 0x10

#define Score_Unit_3_val_1 0xe0
#define Score_Unit_3_val_2 0x10
#define Score_Unit_3_val_3 0x10
#define Score_Unit_3_val_4 0x60
#define Score_Unit_3_val_5 0x10
#define Score_Unit_3_val_6 0x10
#define Score_Unit_3_val_7 0x10
#define Score_Unit_3_val_8 0xe0

#define Score_Unit_2_val_1 0x60
#define Score_Unit_2_val_2 0x90
#define Score_Unit_2_val_3 0x10
#define Score_Unit_2_val_4 0x20
#define Score_Unit_2_val_5 0x40
#define Score_Unit_2_val_6 0x80
#define Score_Unit_2_val_7 0x80
#define Score_Unit_2_val_8 0xf0

#define Score_Unit_1_val_1 0x20
#define Score_Unit_1_val_2 0x60
#define Score_Unit_1_val_3 0x20
#define Score_Unit_1_val_4 0x20
#define Score_Unit_1_val_5 0x20
#define Score_Unit_1_val_6 0x20
#define Score_Unit_1_val_7 0x20
#define Score_Unit_1_val_8 0x70

#define Score_Unit_0_val_1 0x60
#define Score_Unit_0_val_2 0x90
#define Score_Unit_0_val_3 0x90
#define Score_Unit_0_val_4 0x90
#define Score_Unit_0_val_5 0x90
#define Score_Unit_0_val_6 0x90
#define Score_Unit_0_val_7 0x90
#define Score_Unit_0_val_8 0x60

///////////////////////////////
#define Score_D_9_val_1 0x0C
#define Score_D_9_val_2 0x12
#define Score_D_9_val_3 0x12
#define Score_D_9_val_4 0x0E
#define Score_D_9_val_5 0x01
#define Score_D_9_val_6 0x01
#define Score_D_9_val_7 0x01
#define Score_D_9_val_8 0x01

#define Score_D_8_val_1 0x0C
#define Score_D_8_val_2 0x12
#define Score_D_8_val_3 0x12
#define Score_D_8_val_4 0x0C
#define Score_D_8_val_5 0x12
#define Score_D_8_val_6 0x12
#define Score_D_8_val_7 0x12
#define Score_D_8_val_8 0x0C

#define Score_D_7_val_1 0x1E
#define Score_D_7_val_2 0x02
#define Score_D_7_val_3 0x02
#define Score_D_7_val_4 0x0E
#define Score_D_7_val_5 0x02
#define Score_D_7_val_6 0x02
#define Score_D_7_val_7 0x02
#define Score_D_7_val_8 0x02

#define Score_D_6_val_1 0x0E
#define Score_D_6_val_2 0x10
#define Score_D_6_val_3 0x10
#define Score_D_6_val_4 0x0C
#define Score_D_6_val_5 0x12
#define Score_D_6_val_6 0x12
#define Score_D_6_val_7 0x12
#define Score_D_6_val_8 0x0C

#define Score_D_5_val_1 0x1E
#define Score_D_5_val_2 0x10
#define Score_D_5_val_3 0x10
#define Score_D_5_val_4 0x1C
#define Score_D_5_val_5 0x02
#define Score_D_5_val_6 0x02
#define Score_D_5_val_7 0x02
#define Score_D_5_val_8 0x1C

#define Score_D_4_val_1 0x12
#define Score_D_4_val_2 0x12
#define Score_D_4_val_3 0x12
#define Score_D_4_val_4 0x0E
#define Score_D_4_val_5 0x02
#define Score_D_4_val_6 0x02
#define Score_D_4_val_7 0x02
#define Score_D_4_val_8 0x02

#define Score_D_3_val_1 0x1C
#define Score_D_3_val_2 0x02
#define Score_D_3_val_3 0x02
#define Score_D_3_val_4 0x0C
#define Score_D_3_val_5 0x02
#define Score_D_3_val_6 0x02
#define Score_D_3_val_7 0x02
#define Score_D_3_val_8 0x1C

#define Score_D_2_val_1 0x0c
#define Score_D_2_val_2 0x12
#define Score_D_2_val_3 0x02
#define Score_D_2_val_4 0x04
#define Score_D_2_val_5 0x08
#define Score_D_2_val_6 0x10
#define Score_D_2_val_7 0x10
#define Score_D_2_val_8 0x1e

#define Score_D_1_val_1 0x04
#define Score_D_1_val_2 0x0c
#define Score_D_1_val_3 0x04
#define Score_D_1_val_4 0x04
#define Score_D_1_val_5 0x04
#define Score_D_1_val_6 0x04
#define Score_D_1_val_7 0x04
#define Score_D_1_val_8 0x0e

#define Score_D_0_val_1 0x0c
#define Score_D_0_val_2 0x12
#define Score_D_0_val_3 0x12
#define Score_D_0_val_4 0x12
#define Score_D_0_val_5 0x12
#define Score_D_0_val_6 0x12
#define Score_D_0_val_7 0x12
#define Score_D_0_val_8 0x0c

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


void LCD_GameOverScreenWinner(uint8_t selector,uint8_t score);
void LCD_GameOverScreenLoser(uint8_t selector,uint8_t score);

void LCD_GameToLCD(game_info_t * gameInfo,uint8_t selector);





#endif /* LCD_NOKIA_H_ */
