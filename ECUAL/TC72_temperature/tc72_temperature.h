 /******************************************************************************
 *
 * Module: TC72 temperature
 *
 * File Name: TC72_temperature.h
 *
 * Description: Header file for the TC72 temperature sensor using SPI prepheral
 *
 * Author: 	Hesham Shehata
 *
 *******************************************************************************/
 
#ifndef TC72_TEMPERATURE_H
#define TC72_TEMPERATURE_H

#include "../../MCUAL/SPI/spi.h"
#include "../../MCUAL/DIO/DIO.h"
/*configure pins connected to TC72 temperature*/
#define SPI_PORT_NUM 		PORTB_ID
#define SPI_PIN_SS          PIN4_ID





#define CONTROL_READ_ADDRESS  				0x00
#define CONTROL_WRITE_ADDRESS  				0x80
#define LSB_TEMPERATURE_READ_ADDRESS		0x01
#define MSB_TEMPERATURE_READ_ADDRESS		0x02

typedef enum
{
	CONTINOUS_TEMP_CONVERSION = 0,
	SHUTDOWN = 1,
	ONESHOT = 3
}TC72_mode;


/*
* Description:
* function to init TC72 with mode wanted
*/
void TC72_init(TC72_mode mode_parameter);

/*
* Description:
* function to read data from tc72 like MSB & LSB of temperature
*/
sint16_t TC72_readRegister(uint8_t address );

/*
* Description:
* function to write data to TC72 like access control register to set mode wanted
*/
void TC72_writeRrgister(uint8_t address,uint8_t data );

/*
* Description:
* function to enable SS bit in AVR MCU
*/
void TC72_enabeSelect(void);

/*
* Description:
* function to disable SS bit in AVR MCU
*/
void TC72_disableSelect(void);


void TC72_temperatureRead(float *temperatureValue);

void TC72_displayTemperature (float temperature);


#endif
