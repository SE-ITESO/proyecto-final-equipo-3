/*@File 	I2C.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the I2C Protocol configuration
 *@Brief	and functions
 *
*/

#include "I2C.h"

void I2C_init(){
    static uint32_t sourceClock;
	static i2c_master_config_t masterConfig;

	I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = I2C_BAUDRATE;
	sourceClock = I2C_MASTER_CLK_FREQ;
	I2C_MasterInit(I2C0, &masterConfig, sourceClock);
}

status_t I2C_read(uint8_t * data,uint16_t sub_address,uint32_t data_size_for_I2C){
	static i2c_master_transfer_t masterXfer;
	static status_t status;
	masterXfer.slaveAddress   = I2C_24C32D_ADDRESS;		//address de memoria
	masterXfer.subaddress     = sub_address;			//direccion
	masterXfer.data           = data;					//data
	masterXfer.dataSize       = data_size_for_I2C;		//cuantos bytes de data
	masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;
	masterXfer.direction      = kI2C_Read;
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	status = I2C_MasterTransferBlocking(I2C0, &masterXfer);
	return status;
}

status_t I2C_write(uint8_t * data,uint16_t sub_address,uint8_t data_size_for_I2C){
	static i2c_master_transfer_t masterXfer;
	masterXfer.slaveAddress   = I2C_24C32D_ADDRESS;			//address de la memoria
	masterXfer.subaddress     = sub_address;				//direccion
	masterXfer.data           = data;						//data
	masterXfer.dataSize       = data_size_for_I2C;			//cuantos bytes de data
	masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;	//cuantos bytes hay en subaddress
	masterXfer.direction      = kI2C_Write;						//modo
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	return I2C_MasterTransferBlocking(I2C0, &masterXfer);
}



