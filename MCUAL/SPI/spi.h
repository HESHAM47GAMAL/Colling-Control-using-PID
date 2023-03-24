 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.h
 *
 * Description: Header file for the SPI AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "../../utilities/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*
 * Default SPI data value used in case we need to receive a byte from the other device,
 * without need to send a data to it
 */
#define SPI_DEFAULT_DATA_VALUE 0xFF

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
typedef enum
{
	SLAVE,
	MASTER

}SPI_MasterSlaveTypes;
typedef enum
{
	IDLE_LOW ,/*mean that clock rising then falling*/
	IDLE_HIGH /*mean that clock falling then rising*/
}SPI_CLOCKPOLARITY;
typedef enum
{

	SAMPLE_SHIFT_DATA, /*mean clock sample data then shift (setup) data */ /*sample is first transition*/
	SHIFT_SAMPLE_DATA  /*mean clock shift (setup) data then sample data */ /*sample is second transition*/
}SPI_CLOCKPHASE;


/*this new data type should create variable and pass value to init function*/
typedef struct
{
	SPI_MasterSlaveTypes  MasterSlaveTypes;
	SPI_CLOCKPOLARITY  	  CLOCKPOLARITY;
	SPI_CLOCKPHASE		  CLOCKPHASE;
}SPI_configType;

void SPI_init( SPI_configType* SPI_ConfigParameter);
/*
 * Description :
 * Initialize the SPI device as Master.
 */
void SPI_initMaster(void); 

/*
 * Description :
 * Initialize the SPI device as Slave.
 */
void SPI_initSlave(void);


void SPI_sendByte(uint8_t data);
/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
uint8_t SPI_sendReceiveByte(uint8_t data);

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(const uint8_t *str);

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_receiveString(uint8_t *str);

#endif
