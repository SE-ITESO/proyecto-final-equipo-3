/*@File 	I2C.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros and data types
 *			for the use of I2C Protocol
*/

#ifndef I2C_H_
#define I2C_H_

#include "fsl_i2c.h"

typedef enum{
	RTC_Hour,
	RTC_Date,
	Log,
	TemperatureAndHumidity,
}I2C_selector_t;

#define I2C_MASTER_CLK_SRC          I2C0_CLK_SRC
#define I2C_MASTER_CLK_FREQ         CLOCK_GetFreq(I2C0_CLK_SRC)
#define I2C_BAUDRATE               	100000U

#define I2C_RTC_ADDRESS 			0x68U
#define I2C_AM2320_ADDRESS 			0x5CU
#define I2C_24C32D_ADDRESS 			0x50U

#define I2C_AM2320_COMMAND		 	0x3

#define I2C_DATA_SIZE_RTC 			3
#define I2C_DATA_SIZE_AM2320  		6

#define I2C_DATA_SIZE_SMALL 		1
#define I2C_BASE_SUBADDRESS_HOUR 		0X00
#define I2C_BASE_SUBADDRESS_DATE 		0X04
#define I2C_BASE_SUBADDRESS_TEMPERATURE 0X00
#define I2C_SUBADDRESS_SQWE				0X07
#define I2C_SUBADDRESS_SIZE			1
#define I2C_SUBADDRESS_SIZE_LOG		2

#define I2C_RTC_MASK_UNITS			0xF
#define I2C_RTC_MASK_TENS			0x70
#define I2C_RTC_MASK_TENS_HOURS		0x30
#define I2C_RTC_MASK_TENS_YEARS 	0xF0

#define I2C_MASK_TEMP_SIGN			7
#define I2C_SHIFT4					4
#define I2C_SHIFT8					8
#define I2C_MASK7BITS				0x7F

void I2C_init();
status_t I2C_SQWE_config();
status_t I2C_read(uint8_t * data,I2C_selector_t selector,uint16_t sub_address,uint8_t data_size_for_I2C);
status_t I2C_write(uint8_t * data,I2C_selector_t selector,uint16_t sub_address,uint8_t data_size_for_I2C);

#endif /* I2C_H_ */
