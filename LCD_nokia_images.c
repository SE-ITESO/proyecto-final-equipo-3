/*@File 	LCD_nokia_images.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of retriving the bitmap for a Band's Logo
*/

#include "LCD_nokia_images.h"

const uint8_t BASE[] = {
		//los primeros 84 valores no son zona de juego
		0xcc, 0x00, 0xf8, 0x80, 0x80, 0xf8, 0x08, 0x08, 0xf8, 0x00, 0x00, 0xff, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0x00, 0x20, 0x30, 0x38, 0xbc, 0x38, 0x30,
		0x20, 0x00, 0x00, 0x00, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x00, 0xff, 0x00, 0x11, 0x11, 0xd3, 0xd5, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x10,
		0xf0, 0x00, 0x00, 0xCC,

		//COL 9
		//(|C0 por el borde del renglon)
		0xcc, 0x00, 0xc4, 0x44, 0x44, 0xc4, 0x84, 0x44, 0x44, 0x00, 0x00, 0xff, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x20, 0x24, 0x26, 0x27, 0x27, 0x27, 0x26,
		0x24, 0x20, 0x20, 0x20, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,	0x20, 0x20, 0x20, 0x20,
		0x20, 0x3f, 0x20, 0x28, 0x28, 0x2c, 0x2a, 0x2a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x00, 0xe1, 0x01, 0x01, 0xe1, 0x21, 0x21,
		0xe1, 0x00, 0x00, 0xCC,

		//COL 6, 7, 8, 9
		//(|80)(|70)(|E)(|1)
		0xcc, 0x00, 0xe7, 0x04, 0x04, 0x07, 0x04, 0x04,	0x04, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xe1, 0x01, 0x01, 0x81, 0x00, 0x00,
		0xe1, 0x00, 0x00, 0xCC,
		//COL 4,5,6
		//(|E0)(|1C)(|3)
		0xcc, 0x00, 0xcf, 0x01,	0x01, 0x01, 0x01, 0x01, 0xc1, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xe3, 0x02, 0x02, 0x03, 0x02, 0x02,
		0x03, 0x00, 0x00, 0xCC,
		//COL 1,2,3,
		//(|C0)(|38)(|7)
		0xcc, 0x00, 0xe7, 0x04, 0x04, 0x07, 0x04, 0x04, 0x07, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x0f, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x00, 0x00, 0xCC,

		//COL 0 , 1
		//(|E)(|1)
		//(1|E  por el borde del renglon)
		0xcc, 0x00, 0x0f, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0xff, 0xb0, 0x50, 0xb0, 0x50,
		0xb0, 0x50, 0xb0, 0x50, 0xb0, 0x50, 0xb0, 0x50, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,	0x10, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,	0x10, 0x10, 0x10, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x00, 0x02, 0x02,	0x02, 0x02, 0x02, 0x02,
		0x02, 0x00, 0x00, 0xCC
		};

const uint8_t LoadingImage[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x20, 0x20, 0x30, 0x30, 0x30, 0x38, 0x38, 0x3C, 0x3C, 0x7C, 0x7C, 0x7C, 0xFC, 0xFE, 0xFE,
		0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE,
		0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0x7C, 0x7C, 0x7C, 0x7C, 0x3C, 0x38, 0x38, 0x30, 0x30,
		0x30, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xF8, 0xE0,
		0x80, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
		0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0xFD, 0xF9, 0x79, 0x7B, 0x33, 0xB7, 0x87, 0x87, 0xCF, 0xCF, 0xC7,
		0x87, 0xB7, 0x37, 0x73, 0x7B, 0xF9, 0xFD, 0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1E, 0x04, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xFE, 0xFC,
		0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x01, 0x03, 0x07,
		0x0F, 0x1F, 0x1F, 0x0F, 0x67, 0xF7, 0xF3, 0x9B, 0x9D, 0x9C, 0x9C, 0x9E, 0x9F, 0x9F, 0x9F, 0x9F,
		0x9F, 0x00, 0x00, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x9E, 0x9C, 0x9C, 0x9D, 0x9B, 0xF3, 0xF7, 0x67,
		0x4F, 0x1F, 0x1F, 0x0F, 0x0F, 0x07, 0x03, 0x81, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0x00, 0x00, 0x1F, 0x7F, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x9F, 0xCF, 0xE7, 0xF3, 0xFB,
		0xFD, 0xFC, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0xC1, 0x83, 0x83, 0x07, 0x07,
		0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x70, 0x70, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x07, 0x07, 0x83, 0x83,
		0xC1, 0xC0, 0xE0, 0xF0, 0xF0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFC, 0xF9, 0xF3, 0xF3, 0xC7, 0x8F,
		0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x00,
		0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x3F, 0x0F, 0x03, 0x00, 0x08, 0x1E, 0x3F,
		0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F, 0x87,
		0x87, 0x83, 0xC3, 0xC3, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xC2,
		0xC3, 0xC3, 0x87, 0x87, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F,
		0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1C, 0x00, 0x01, 0x03, 0x0F, 0x3F, 0x3F, 0x1F, 0x0F, 0x07, 0x03,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x0C, 0x0C, 0x0C, 0x1C, 0x1E, 0x1E, 0x1E, 0x1E, 0x3E,
		0x3F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
		0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x3E, 0x3E, 0x1E, 0x1E, 0x1E,
		0x1C, 0x1C, 0x0C, 0x0C, 0x0C, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};

const uint8_t Main[LCD_BITMAP_SIZE] = {
		0xcc, 0x01, 0x01, 0x00, 0x00, 0xf1, 0x01, 0x00, 0xe0, 0x11, 0x11, 0xe0, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x20, 0x71, 0x01, 0x00, 0xc8, 0x09, 0x09, 0x08,
		0x00, 0xc9, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x08, 0x09, 0x09, 0x08, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x20,
		0x60, 0x41, 0x01, 0xcc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x11, 0x11, 0x10, 0x10, 0x10, 0x7d,
		0x00, 0x00, 0xce, 0x11, 0x11, 0x91, 0x51, 0x51, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xb3, 0x5a, 0x5b, 0x5a, 0x1a, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0xaa, 0xea, 0x00, 0x00, 0x40, 0xe0, 0x40, 0x40, 0x40,
		0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x38, 0xfe, 0x7c, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0xbe, 0x21, 0x21,
		0x3e, 0x24, 0x22, 0x21, 0x00, 0x00, 0xf3, 0x04, 0x04, 0xc3, 0x00, 0x00, 0xf7, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x38, 0x4d, 0x4d, 0x4d, 0x4d, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xba, 0xaa, 0xbb, 0x00, 0x00, 0x00,
		0x00, 0x76, 0x54, 0x74, 0x10, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x54, 0x5c, 0x04, 0x1c, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x00,
		0x00, 0xbf, 0x04, 0x04, 0x04, 0x04, 0x04, 0x84, 0x00, 0x00, 0xfd, 0x21, 0x21, 0x21, 0x21, 0x21,
		0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x08, 0xe7, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x73, 0x52,
		0x73, 0x00, 0x00, 0x02, 0x37, 0x62, 0x12, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x75,
		0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc,
		0xcc, 0x00, 0x00, 0x00, 0x00, 0xef, 0x08, 0x08, 0x0e, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x7d, 0x10,
		0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0xa1, 0xb1, 0xa1,
		0xa1, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x41, 0x41, 0xdd, 0x55, 0x5d, 0x00, 0x00, 0x80, 0xc0, 0x9c, 0x94, 0x9c, 0x00, 0x00, 0x00, 0x10,
		0x10, 0xd7, 0x55, 0xd7, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x80, 0x80, 0x0f, 0x01, 0x81, 0x81, 0x01, 0x01, 0x81,
		0x80, 0x00, 0x08, 0x88, 0x8c, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80,
		0x91, 0x11, 0x15, 0x95, 0x95, 0x0b, 0x00, 0x80, 0x80, 0x00, 0x0c, 0x8c, 0x80, 0x00, 0x00, 0x80,
		0x80, 0x00, 0x00, 0x80, 0x81, 0x01, 0x01, 0x81, 0x81, 0x00, 0x00, 0x80, 0x81, 0x00, 0x00, 0x80,
		0x80, 0x00, 0x00, 0x80, 0x80, 0x01, 0x01, 0x81, 0x81, 0x01, 0x00, 0x80, 0x80, 0x02, 0x0e, 0x80,
		0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0xcc
};

const uint8_t WINNER[LCD_BITMAP_SIZE] = {
		0xcc, 0x01, 0x81, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x81, 0x01, 0x00, 0x00, 0x01, 0x81, 0x80,
		0x80, 0x81, 0xf1, 0xf0, 0xf0, 0xf1, 0x01, 0x00, 0x98, 0x01, 0x01, 0x00, 0x18, 0x19, 0x19, 0x18,
		0x18, 0x01, 0x19, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x98, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0xcc, 0xcc, 0x00, 0x07, 0x07, 0x07, 0x07, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x78,
		0x78, 0x78, 0x07, 0x07, 0x07, 0x07, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00,
		0xa6, 0xb6, 0xae, 0xa6, 0xa6, 0xa6, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x54,
		0xd4, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x7f, 0x3e, 0x1c, 0x08, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x78, 0x40, 0x60, 0x40, 0x40, 0x78, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00,
		0x99, 0x00, 0x00, 0x00, 0x8d, 0x8d, 0x8d, 0xad, 0xad, 0xad, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x38, 0xa2, 0xb0, 0x22, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x75, 0x55, 0x77, 0x00, 0x00, 0x00, 0x00, 0xa8, 0xa8, 0xb8, 0x88, 0x08, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x15, 0x91, 0x91, 0x51, 0x00, 0x00, 0x7b, 0x42, 0x62, 0x43,
		0x42, 0x7a, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x70, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x94, 0x94, 0x97, 0x64, 0x00, 0x00, 0x00, 0x00, 0x99,
		0x00, 0x00, 0x00, 0x00, 0x21, 0x21, 0xe7, 0xa5, 0xe7, 0x00, 0x00, 0x08, 0x08, 0xeb, 0xaa, 0xeb,
		0x80, 0x80, 0x00, 0xae, 0xaa, 0xaa, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc,
		0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x05, 0x05, 0xcf, 0x48, 0x90, 0x00, 0x00,
		0x91, 0x51, 0x51, 0x4a, 0x4a, 0x84, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x9c, 0xa6, 0xa6, 0x26,
		0x26, 0x26, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x10, 0x90, 0x50, 0x8e, 0x00,
		0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0xba, 0xaa, 0xba, 0x00, 0x00, 0x00,
		0x80, 0x38, 0x28, 0x38, 0x00, 0x00, 0x00, 0xbb, 0xaa, 0xbb, 0x88, 0x08, 0x38, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc, 0xcc, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x83, 0x04, 0x04, 0x85,
		0x84, 0x03, 0x00, 0x80, 0x83, 0x04, 0x04, 0x84, 0x84, 0x03, 0x00, 0x80, 0x99, 0x00, 0x00, 0x80,
		0x91, 0x11, 0x13, 0x8f, 0x86, 0x06, 0x06, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x01, 0x82,
		0x81, 0x00, 0x03, 0x80, 0x80, 0x00, 0x00, 0x99, 0x80, 0x00, 0x00, 0x80, 0x82, 0x02, 0x03, 0x82,
		0x82, 0x00, 0x00, 0x81, 0x83, 0x01, 0x01, 0x81, 0x80, 0x00, 0x00, 0x83, 0x82, 0x03, 0x00, 0x80,
		0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0xcc
};

const uint8_t LOSER[LCD_BITMAP_SIZE] = {
		0xcc, 0x01, 0x81, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x81, 0x01, 0x00, 0x00, 0x01, 0x81, 0x80,
		0x80, 0x81, 0xf1, 0xf0, 0xf0, 0xf1, 0x01, 0x00, 0x98, 0x01, 0x01, 0x00, 0xd8, 0xd9, 0x19, 0x98,
		0x18, 0x01, 0xd9, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x98, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,
		0x00, 0x01, 0x01, 0xcc,

		0xcc, 0x00, 0x07, 0x07, 0x07, 0x07, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x78, 0x78, 0x78, 0x07, 0x07,
		0x07, 0x07, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00,	0x1d, 0xa1, 0xa1, 0xbd,
		0x85, 0x85, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x54,	0xd4, 0x00, 0x00, 0x00,
		0x1c, 0x1c, 0x1c, 0x1c, 0x7f, 0x3e, 0x1c, 0x08, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc,

		0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x78, 0x40, 0x60, 0x40,	0x40, 0x78, 0x00, 0x00,
		0x80, 0x40, 0x40, 0x80, 0x80, 0x40, 0x00, 0x00,	0x99, 0x00, 0x00, 0x00, 0x07, 0x09, 0x09, 0x09,
		0x09, 0xe9, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x38, 0xa2, 0xb0, 0x22, 0xb8, 0x00,
		0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x75, 0x55, 0x77, 0x00, 0x00, 0x00,
		0x00, 0xa8, 0xa8, 0xb8, 0x88, 0x08, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc,

		0xcc, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x15, 0x91, 0x91, 0x51, 0x00, 0x00,
		0x7b, 0x42, 0x62, 0x43,	0x42, 0x7a, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x99,
		0x99, 0x99, 0x71, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x94, 0x94, 0x97, 0x64, 0x00,
		0x00, 0x00, 0x00, 0x99,	0x00, 0x00, 0x00, 0x00, 0x21, 0x21, 0xe7, 0xa5, 0xe7, 0x00, 0x00, 0x08,
		0x08, 0xeb, 0xaa, 0xeb,	0x80, 0x80, 0x00, 0xae, 0xaa, 0xaa, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc,

		0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x05, 0x05, 0xcf, 0x48, 0x90, 0x00, 0x00,
		0x91, 0x51, 0x51, 0x4a, 0x4a, 0x84, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x9c, 0xa6, 0xa6, 0x26,
		0x26, 0x26, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x10, 0x90, 0x50, 0x8e, 0x00,
		0x00, 0x00, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x82, 0x82, 0xba, 0xaa, 0xba, 0x00, 0x00, 0x00,
		0x80, 0x38, 0x28, 0x38, 0x00, 0x00, 0x00, 0xbb, 0xaa, 0xbb, 0x88, 0x08, 0x38, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xcc,

		0xcc, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x83, 0x04, 0x04, 0x85,	0x84, 0x03, 0x00, 0x80,
		0x83, 0x04, 0x04, 0x84, 0x84, 0x03, 0x00, 0x80, 0x99, 0x00, 0x00, 0x80,	0x91, 0x11, 0x13, 0x8f,
		0x86, 0x06, 0x06, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x01, 0x82,	0x81, 0x00, 0x03, 0x80,
		0x80, 0x00, 0x00, 0x99, 0x80, 0x00, 0x00, 0x80, 0x82, 0x02, 0x03, 0x82,	0x82, 0x00, 0x00, 0x81,
		0x83, 0x01, 0x01, 0x81, 0x80, 0x00, 0x00, 0x83, 0x82, 0x03, 0x00, 0x80,	0x80, 0x00, 0x00, 0x80,
		0x80, 0x00, 0x00, 0xcc
};

void LCD_image_GetMainMenu(uint8_t * picture){
	/** Funcion para recuperar el arreglo del Mapa de Juego **/
	for(int i=0;i<LCD_BITMAP_SIZE;i++){
		picture[i] = Main[i];
	}
}

void LCD_image_GetArena(uint8_t * picture){
	/** Funcion para recuperar el arreglo del Mapa de Juego **/
	for(int i=0;i<LCD_BITMAP_SIZE;i++){
		picture[i] = BASE[i];
	}
}

void LCD_image_GetLoadingImage(uint8_t * picture){
	/** Funcion para recuperar la imagen de carga **/
	for(int i=0;i<LCD_BITMAP_SIZE;i++){
		picture[i] = LoadingImage[i];
	}
}

void LCD_image_GetWinnerImage(uint8_t * picture){
	/** Funcion para recuperar la imagen de carga **/
	for(int i=0;i<LCD_BITMAP_SIZE;i++){
		picture[i] = WINNER[i];
	}
}
void LCD_image_GetLoserImage(uint8_t * picture){
	/** Funcion para recuperar la imagen de carga **/
	for(int i=0;i<LCD_BITMAP_SIZE;i++){
		picture[i] = LOSER[i];
	}
}
