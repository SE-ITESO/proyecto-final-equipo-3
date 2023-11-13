/*@File 	LCD_nokia.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting the use for the LCD screen
*/

#include "LCD_nokia.h"




static const uint8_t ASCII[][5] =
{
 {0x00, 0x00, 0x00, 0x00, 0x00} // 20
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c �
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e
,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f
};


static void LCD_nokia_delay(void)
{
	int counter;

	for(counter=0; counter<1500; counter++)
	{

	}
}


void LCD_nokia_init(void)
{
	/**Funcion para inicializar la pantalla LCD**/
	GPIO_set_pin_value_off(C, RESET_PIN);
	LCD_nokia_delay();
	GPIO_set_pin_value_on(C, RESET_PIN);

	LCD_nokia_write_byte(LCD_CMD, 0x21,LCD_0); //Tell LCD that extended commands follow
	LCD_nokia_write_byte(LCD_CMD, 0xBF,LCD_0); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
	LCD_nokia_write_byte(LCD_CMD, 0x04,LCD_0); //Set Temp coefficent
	LCD_nokia_write_byte(LCD_CMD, 0x14,LCD_0); //LCD bias mode 1:48: Try 0x13 or 0x14

	LCD_nokia_write_byte(LCD_CMD, 0x20,LCD_0); //We must send 0x20 before modifying the display control mode
	LCD_nokia_write_byte(LCD_CMD, 0x0C,LCD_0); //Set display control, normal mode. 0x0D for inverse

	LCD_nokia_write_byte(LCD_CMD, 0x21,LCD_1); //Tell LCD that extended commands follow
	LCD_nokia_write_byte(LCD_CMD, 0xBF,LCD_1); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
	LCD_nokia_write_byte(LCD_CMD, 0x04,LCD_1); //Set Temp coefficent
	LCD_nokia_write_byte(LCD_CMD, 0x14,LCD_1); //LCD bias mode 1:48: Try 0x13 or 0x14

	LCD_nokia_write_byte(LCD_CMD, 0x20,LCD_1); //We must send 0x20 before modifying the display control mode
	LCD_nokia_write_byte(LCD_CMD, 0x0C,LCD_1); //Set display control, normal mode. 0x0D for inverse
}

void LCD_nokia_bitmap(uint8_t bitmap[],uint8_t lcdScreen_selector){
	/**Funcion para mandar un bitmap a la pantalla LCD**/
	dspi_transfer_t masterXfer;
    GPIO_set_pin_value_on(C, DATA_OR_CMD_PIN);
   
   	masterXfer.txData = bitmap;          /*!< Send buffer. */
   	masterXfer.rxData = 0;          /*!< Receive buffer. */
   	masterXfer.dataSize = 504; /*!< Transfer bytes. */
   	if(LCD_0 == lcdScreen_selector)
   		masterXfer.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous; //CTAR0
   	else
   		masterXfer.configFlags = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous; //CTAR0

   	DSPI_MasterTransferBlocking(SPI0, &masterXfer);
}

void LCD_nokia_write_byte(uint8_t data_or_command, uint8_t data,uint8_t lcdScreen_selector)
{
	dspi_transfer_t masterXfer;

	if(data_or_command)
		GPIO_set_pin_value_on(C, DATA_OR_CMD_PIN);
	else
		GPIO_set_pin_value_off(C, DATA_OR_CMD_PIN);

	masterXfer.txData = &data;          /*!< Send buffer. */
	masterXfer.rxData = 0;          /*!< Receive buffer. */
	masterXfer.dataSize = 1; /*!< Transfer bytes. */
	if(LCD_0 == lcdScreen_selector)
	   		masterXfer.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous; //CTAR0
	   	else
	   		masterXfer.configFlags = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous; //CTAR0
	DSPI_MasterTransferBlocking(SPI0, &masterXfer);
}

void LCD_nokia_send_char(uint8_t character,uint8_t lcdScreen_selector) {
  uint16_t index = 0;

  LCD_nokia_write_byte(LCD_DATA, 0x00,lcdScreen_selector); //Blank vertical line padding

  for (index = 0 ; index < 5 ; index++)
	  LCD_nokia_write_byte(LCD_DATA, ASCII[character - 0x20][index],lcdScreen_selector);
    //0x20 is the ASCII character for Space (' '). The font table starts with this character
  LCD_nokia_write_byte(LCD_DATA, 0x00,lcdScreen_selector); //Blank vertical line padding
}

void LCD_nokia_send_string(uint8_t characters [],uint8_t lcdScreen_selector) {
  while (*characters)
	  LCD_nokia_send_char(*characters++, lcdScreen_selector);
}

void LCD_nokia_clear(uint8_t lcdScreen_selector) {
	/**Funcion para limpiar la pantalla LCD**/
	uint16_t index = 0;
  for (index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
	  LCD_nokia_write_byte(LCD_DATA, 0x00, lcdScreen_selector);
  LCD_nokia_goto_xy(0, 0,lcdScreen_selector); //After we clear the display, return to the home position
}

void LCD_nokia_goto_xy(uint8_t x, uint8_t y,uint8_t lcdScreen_selector) {
	LCD_nokia_write_byte(LCD_CMD, 0x80 | x,lcdScreen_selector);  // Column.
	LCD_nokia_write_byte(LCD_CMD, 0x40 | y,lcdScreen_selector);  // Row.  ?
}

void LCD_LoadingScreen(){
	static uint8_t picture[SIZE_IN_BYTES];
	LCD_image_GetLoadingImage(picture);
	LCD_nokia_clear(LCD_0);
	LCD_nokia_clear(LCD_1);
	LCD_nokia_bitmap(picture,LCD_0);
	LCD_nokia_bitmap(picture,LCD_1);
}

void LCD_nokia_wdog(){
	static uint8_t wdog_error_msg1[] = "ERROR:";
	static uint8_t wdog_error_msg2[] = "WDOG RESET";
	LCD_nokia_clear(LCD_0);
	LCD_nokia_goto_xy(25,1,LCD_0);
	LCD_nokia_send_string(wdog_error_msg1,LCD_0);
	LCD_nokia_goto_xy(10,3,LCD_0);
	LCD_nokia_send_string(wdog_error_msg2,LCD_0);
	LCD_nokia_clear(LCD_1);
	LCD_nokia_goto_xy(25,1,LCD_1);
	LCD_nokia_send_string(wdog_error_msg1,LCD_1);
	LCD_nokia_goto_xy(10,3,LCD_1);
	LCD_nokia_send_string(wdog_error_msg2,LCD_1);
}


void LCD_MenuScreen(){
	static uint8_t picture[SIZE_IN_BYTES];
	LCD_image_GetMainMenu(picture);
	LCD_nokia_clear(LCD_0);
	LCD_nokia_clear(LCD_1);
	LCD_nokia_bitmap(picture,LCD_0);
	LCD_nokia_bitmap(picture,LCD_1);
}

void LCD_GameOverScreenWinner(uint8_t selector){
	//falta añadirle el score
	static uint8_t picture[SIZE_IN_BYTES];
	LCD_image_GetWinnerImage(picture);
	if(1 == selector){
		LCD_nokia_clear(LCD_0);
		LCD_nokia_bitmap(picture,LCD_0);
	}
	else{
		LCD_nokia_clear(LCD_1);
		LCD_nokia_bitmap(picture,LCD_1);
	}
}

void LCD_GameOverScreenLoser(uint8_t selector){
	//falta añadirle el score
	static uint8_t picture[SIZE_IN_BYTES];
	LCD_image_GetLoserImage(picture);
	if(1 == selector){
		LCD_nokia_clear(LCD_0);
		LCD_nokia_bitmap(picture,LCD_0);
	}
	else{
		LCD_nokia_clear(LCD_1);
		LCD_nokia_bitmap(picture,LCD_1);
	}
}





static void LCD_image_to_game (uint8_t * picture, uint16_t fila, uint16_t columna){
	static uint32_t dato =0;
	switch(columna){
	    case 9:
	        dato = MAP_offset_1+(3*fila);
	        picture[dato]|= MAP_COL_9A_MASK;
	        dato++;
	        picture[dato]|= MAP_COL_9A_MASK;
	        dato++;
	        picture[dato]|= MAP_COL_9A_MASK;
	        dato = 180+(3*fila);
	        picture[dato]|= MAP_COL_9B_MASK;
	        dato ++;
	        picture[dato]|= MAP_COL_9B_MASK;
	       	dato ++;
	        picture[dato]|= MAP_COL_9B_MASK;
	        break;
	    case 8:
	        dato= MAP_offset_2+(3*fila);
	        picture[dato]|= MAP_COL_8_MASK;
	        dato ++;
	        picture[dato]|= MAP_COL_8_MASK;
	        dato ++;
	        picture[dato]|= MAP_COL_8_MASK;
	        break;
	    case 7:
	        dato= MAP_offset_2+(3*fila);
	        picture[dato]|= MAP_COL_7_MASK;
	        dato ++;
	        picture[dato]|= MAP_COL_7_MASK;
	        dato ++;
	        picture[dato]|= MAP_COL_7_MASK;
	        break;
	    case 6:
	        dato= MAP_offset_2+(3*fila);
	        picture[dato]|= MAP_COL_6A_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_6A_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_6A_MASK;
	        dato= MAP_offset_3+(3*fila);
	        picture[dato]|= MAP_COL_6B_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_6B_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_6B_MASK;
	        break;
	    case 5:
	        dato= MAP_offset_3+(3*fila);
	        picture[dato]|= MAP_COL_5_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_5_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_5_MASK;
	        break;
	    case 4:
	        dato= MAP_offset_3+(3*fila);
	        picture[dato]|= MAP_COL_4_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_4_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_4_MASK;
	        break;
	    case 3:
	        dato= MAP_offset_4+(3*fila);
	        picture[dato]|= MAP_COL_3_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_3_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_3_MASK;
	        break;
	    case 2:
	        dato= MAP_offset_4+(3*fila);
	        picture[dato]|= MAP_COL_2_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_2_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_2_MASK;
	        break;
	    case 1:
	        dato= MAP_offset_4+(3*fila);
	        picture[dato]|= MAP_COL_1A_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_1A_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_1A_MASK;
	        dato= MAP_offset_5+(3*fila);
	        picture[dato]|= MAP_COL_1B_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_1B_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_1B_MASK;
	        break;
	    case 0:
	        dato= MAP_offset_5+(3*fila);
	        picture[dato]|= MAP_COL_0_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_0_MASK;
	    	dato ++;
	    	picture[dato]|= MAP_COL_0_MASK;
	        break;
	    }
}



static void LCD_image_to_next (uint8_t * picture, uint16_t fila, uint16_t columna){
	static uint32_t dato=0;
	switch(columna){
		case 3:
			dato= Next_offset_1+(3*fila);
			picture[dato]|= Next_COL_3_MASK;
			dato ++;
			picture[dato]|= Next_COL_3_MASK;
			dato ++;
			picture[dato]|= Next_COL_3_MASK;
			break;
		case 2:
			dato= Next_offset_1+(3*fila);
			picture[dato]|= Next_COL_2_MASK;
			dato ++;
			picture[dato]|= Next_COL_2_MASK;
			dato ++;
			picture[dato]|= Next_COL_2_MASK;
			break;
		case 1:
			dato= Next_offset_1+(3*fila);
			picture[dato]|= Next_COL_1A_MASK;
			dato ++;
			picture[dato]|= Next_COL_1A_MASK;
			dato ++;
			picture[dato]|= Next_COL_1A_MASK;
			dato= Next_offset_2+(3*fila);
			picture[dato]|= Next_COL_1B_MASK;
			dato ++;
			picture[dato]|= Next_COL_1B_MASK;
			dato ++;
			picture[dato]|= Next_COL_1B_MASK;
			break;
		case 0:
			dato= Next_offset_2+(3*fila);
			picture[dato]|= Next_COL_0_MASK;
			dato ++;
			picture[dato]|= Next_COL_0_MASK;
			dato ++;
			picture[dato]|= Next_COL_0_MASK;
			break;
		}
	}



static void LCD_image_to_hold (uint8_t * picture, uint16_t fila, uint16_t columna){
	static uint32_t dato=0;
	switch(columna){
		case 3:
			dato= Hold_offset_1+(3*fila);
			picture[dato]|= Hold_COL_3_MASK;
			dato ++;
			picture[dato]|= Hold_COL_3_MASK;
			dato ++;
			picture[dato]|= Hold_COL_3_MASK;
			break;
		case 2:
			dato= Hold_offset_1+(3*fila);
			picture[dato]|= Hold_COL_2_MASK;
			dato ++;
			picture[dato]|= Hold_COL_2_MASK;
			dato ++;
			picture[dato]|= Hold_COL_2_MASK;
			break;
		case 1:
			dato= Hold_offset_1+(3*fila);
			picture[dato]|= Hold_COL_1A_MASK;
			dato ++;
			picture[dato]|= Hold_COL_1A_MASK;
			dato ++;
			picture[dato]|= Hold_COL_1A_MASK;
			dato= Hold_offset_2+(3*fila);
			picture[dato]|= Hold_COL_1B_MASK;
			dato ++;
			picture[dato]|= Hold_COL_1B_MASK;
			dato ++;
			picture[dato]|= Hold_COL_1B_MASK;
			break;
		case 0:
			dato= Hold_offset_2+(3*fila);
			picture[dato]|= Hold_COL_0_MASK;
			dato ++;
			picture[dato]|= Hold_COL_0_MASK;
			dato ++;
			picture[dato]|= Hold_COL_0_MASK;
			break;
		}
	}


static void LCD_arena_pixel(uint8_t * base, uint8_t arena[][MAP_SIZE_X]){
	uint8_t fila=0;
	uint8_t columna=0;
     for (fila=0;fila<MAP_SIZE_Y;fila++){
        for(columna=0;columna<MAP_SIZE_X;columna++){
            if (1== arena[fila][columna])
                //Hay un pixel prendido en el mapa de juego
                LCD_image_to_game(base,fila,columna);
        }
    }
}

static void LCD_next_pixel(uint8_t * base, uint8_t arena[][MAP_NEXT_SIZE]){
	uint8_t fila=0;
	uint8_t columna=0;
	//Recorre el arreglo bidimensional en busca de 1
     for (fila=0;fila<MAP_NEXT_SIZE;fila++){
        for(columna=0;columna<MAP_NEXT_SIZE;columna++){
            if (1== arena[fila][columna])
                //Hay un pixel prendido en el area de next
                LCD_image_to_next(base,fila,columna);
        }
    }
}

static void LCD_hold_pixel(uint8_t * base, uint8_t arena[][MAP_HOLD_SIZE]){
	uint8_t fila=0;
	uint8_t columna=0;
	//Recorre el arreglo bidimensional en busca de 1
     for (fila=0;fila<MAP_HOLD_SIZE;fila++){
        for(columna=0;columna<MAP_HOLD_SIZE;columna++){
            if (1== arena[fila][columna])
                //Hay un pixel prendido en el area de hold
                LCD_image_to_hold(base,fila,columna);
        }
    }
}


void LCD_GameToLCD(game_info_t * gameInfo,uint8_t selector){
	static uint8_t image[SIZE_IN_BYTES];
	LCD_image_GetArena(image);
	LCD_arena_pixel(image,gameInfo->board);
	LCD_next_pixel(image,gameInfo->next_tetromino.shape);
	LCD_hold_pixel(image,gameInfo->hold_tetromino.shape);
	LCD_nokia_bitmap(image,selector);
}
