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

status_t I2C_SQWE_config(){
	uint8_t oneHzSignal[2] = {0x10,0};
	static i2c_master_transfer_t masterXfer;
	masterXfer.slaveAddress   = I2C_RTC_ADDRESS;		//address del rtc
	masterXfer.direction      = kI2C_Write;				//modo
	masterXfer.subaddress     = I2C_SUBADDRESS_SQWE;	//direccion
	masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;	//cuantos bytes hay en subaddress
	masterXfer.data           = oneHzSignal;			//data
	masterXfer.dataSize       = I2C_DATA_SIZE_SMALL;	//cuantos bytes de data
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	return I2C_MasterTransferBlocking(I2C0, &masterXfer);
}

static void I2C_rtc_to_data(uint8_t * data, uint8_t * rtc_data,uint8_t selector){
	if(0 ==selector){
		data[5] = rtc_data[0] & I2C_RTC_MASK_UNITS;
		data[4] = (rtc_data[0] & I2C_RTC_MASK_TENS)>>I2C_SHIFT4;
		data[3] = rtc_data[1] & I2C_RTC_MASK_UNITS;
		data[2] = (rtc_data[1] & I2C_RTC_MASK_TENS)>>I2C_SHIFT4;
		data[1] = rtc_data[2] & I2C_RTC_MASK_UNITS;
		data[0] = (rtc_data[2] & I2C_RTC_MASK_TENS_HOURS)>>I2C_SHIFT4;
	}
	else{
		data[0] = (rtc_data[0] & I2C_RTC_MASK_TENS)>>I2C_SHIFT4;;
		data[1] = rtc_data[0] & I2C_RTC_MASK_UNITS;
		data[2] = (rtc_data[1] & I2C_RTC_MASK_TENS)>>I2C_SHIFT4;
		data[3] = rtc_data[1] & I2C_RTC_MASK_UNITS;
		data[6] = (rtc_data[2] & I2C_RTC_MASK_TENS_YEARS)>>I2C_SHIFT4;
		data[7] = rtc_data[2] & I2C_RTC_MASK_UNITS;
	}
}

static void I2C_AM2320_to_data(uint8_t * data, uint8_t * sensor_data)
{
	static uint16_t Temp =0;
	static uint16_t Hum=0;
	static uint16_t Centenas = 100;
	static uint16_t Decenas = 10;

	data[0]=sensor_data[4]>>I2C_MASK_TEMP_SIGN; //signo temperatura

	Temp = ((sensor_data[4]&I2C_MASK7BITS) << I2C_SHIFT8) | (sensor_data[5]);
	data[1] = Temp/Centenas;							//decenas temp
	data[2] =(Temp/Decenas) - (data[1]*Decenas);		//unidades temp
	data[3] = Temp%Decenas;								//decimales temp

	Hum = (sensor_data[2] << I2C_SHIFT8) | (sensor_data[3]);
	data[4] = Hum/Centenas;								//decenas hum
	data[5] = (Hum/Decenas) - (data[4]*Decenas);		//unidades hum
	data[6] = Hum%Decenas;								//decimales hum
}


static void I2C_data_to_rtc(uint8_t * data, uint8_t * rtc_data, uint8_t selector){
	if(0 == selector){
		rtc_data[0] = (data[4] << I2C_SHIFT4)|(data[5]);
		rtc_data[1] = (data[2] << I2C_SHIFT4)|(data[3]);
		rtc_data[2] = (data[0] << I2C_SHIFT4)|(data[1]);
	}
	else{
		rtc_data[0] = (data[0] << I2C_SHIFT4)|(data[1]);
		rtc_data[1] = (data[2] << I2C_SHIFT4)|(data[3]);
		rtc_data[2] = (data[6] << I2C_SHIFT4)|(data[7]);
	}
}

status_t I2C_read(uint8_t * data,I2C_selector_t selector,uint16_t sub_address,uint8_t data_size_for_I2C){
	static i2c_master_transfer_t masterXfer;
	static uint8_t rtc_data[3];
	static uint8_t temperature_data[6];
	static status_t status;
	switch(selector){
	case RTC_Hour:
		masterXfer.slaveAddress   = I2C_RTC_ADDRESS;		//address del rtc
		masterXfer.subaddress     = sub_address;
		masterXfer.data           = rtc_data;
		masterXfer.dataSize       = data_size_for_I2C;
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;
		break;
	case RTC_Date:
		masterXfer.slaveAddress   = I2C_RTC_ADDRESS;		//address del rtc
		masterXfer.subaddress     = sub_address;
		masterXfer.data           = rtc_data;
		masterXfer.dataSize       = data_size_for_I2C;
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;
		break;
	case Log:
		masterXfer.slaveAddress   = I2C_24C32D_ADDRESS;		//address de memoria
		masterXfer.subaddress     = sub_address;			//direccion
		masterXfer.data           = data;					//data
		masterXfer.dataSize       = data_size_for_I2C;		//cuantos bytes de data
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE_LOG;
		break;
	case TemperatureAndHumidity:
		masterXfer.slaveAddress   = I2C_AM2320_ADDRESS;		//address del Sensor
		masterXfer.subaddress     = sub_address;
		masterXfer.data           = temperature_data;
		masterXfer.dataSize       = data_size_for_I2C;
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;
		break;
	}

	masterXfer.direction      = kI2C_Read;
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	status = I2C_MasterTransferBlocking(I2C0, &masterXfer);
	switch(selector){
		case RTC_Hour:
			I2C_rtc_to_data(data,rtc_data,0);					//Conversion de formato
			break;
		case RTC_Date:
			I2C_rtc_to_data(data,rtc_data,1);					//Conversion de formato
			break;
		case TemperatureAndHumidity:
			I2C_AM2320_to_data(data,temperature_data);			//Conversion de formato
			break;
		case Log:
			break;
	}
	return status;
}

status_t I2C_write(uint8_t * data,I2C_selector_t selector,uint16_t sub_address,uint8_t data_size_for_I2C){
	static uint8_t rtc_data[3];
	static i2c_master_transfer_t masterXfer;

	switch(selector){
	case RTC_Hour:
		I2C_data_to_rtc(data,rtc_data,0);
		masterXfer.slaveAddress   = I2C_RTC_ADDRESS;			//address del rtc
		masterXfer.subaddress     = I2C_BASE_SUBADDRESS_HOUR;	//direccion
		masterXfer.data           = rtc_data;					//data
		masterXfer.dataSize       = data_size_for_I2C;			//cuantos bytes de data
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;		//cuantos bytes hay en subaddress
		break;
	case RTC_Date:
		I2C_data_to_rtc(data,rtc_data,1);
		masterXfer.slaveAddress   = I2C_RTC_ADDRESS;			//address del rtc
		masterXfer.subaddress     = I2C_BASE_SUBADDRESS_DATE;	//direccion
		masterXfer.data           = rtc_data;					//data
		masterXfer.dataSize       = data_size_for_I2C;			//cuantos bytes de data
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;		//cuantos bytes hay en subaddress
		break;
	case TemperatureAndHumidity:
		masterXfer.slaveAddress   = I2C_AM2320_ADDRESS;			//address del sensor
		masterXfer.subaddress     = I2C_AM2320_COMMAND;			//direccion
		masterXfer.data           = data;						//data
		masterXfer.dataSize       = data_size_for_I2C;			//cuantos bytes de data
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE;		//cuantos bytes hay en subaddress
		break;
	default:
		masterXfer.slaveAddress   = I2C_24C32D_ADDRESS;			//address de la memoria
		masterXfer.subaddress     = sub_address;				//direccion
		masterXfer.data           = data;						//data
		masterXfer.dataSize       = data_size_for_I2C;			//cuantos bytes de data
		masterXfer.subaddressSize = I2C_SUBADDRESS_SIZE_LOG;	//cuantos bytes hay en subaddress
		break;
	}
	masterXfer.direction      = kI2C_Write;						//modo
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	return I2C_MasterTransferBlocking(I2C0, &masterXfer);
}



