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



#define I2C_MASTER_CLK_SRC          I2C0_CLK_SRC
#define I2C_MASTER_CLK_FREQ         CLOCK_GetFreq(I2C0_CLK_SRC)
#define I2C_BAUDRATE               	100000U

#define I2C_24C32D_ADDRESS 			0x50U
#define I2C_SUBADDRESS_SIZE			2

void I2C_init();
status_t I2C_read(uint8_t * data,uint16_t sub_address,uint32_t data_size_for_I2C);
status_t I2C_write(uint8_t * data,uint16_t sub_address,uint8_t data_size_for_I2C);

#endif /* I2C_H_ */
