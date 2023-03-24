 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.c
 *
 * Description: Source file for the SPI AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "spi.h"
#include "../DIO/DIO.h" /* To Setup the SPI pins direction */
#include "../../utilities/common_macros.h" /* To use the macros like SET_BIT */
//#include "../../utilities/MCU_register.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the SPI device .
 */
void SPI_init( SPI_configType* SPI_ConfigParameter)
{
	/*check if config as master or slave*/
	if(SPI_ConfigParameter->MasterSlaveTypes == SLAVE )
	{
		/******** Configure SPI Slave Pins *********
			 * SS(PB4)   --> Input
			 * MOSI(PB5) --> Input
			 * MISO(PB6) --> Output
			 * SCK(PB7) --> Input
			 ********************************************/
			DIO_setupPinDirection(PORTB_ID,PIN4_ID,INPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN5_ID,INPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN6_ID,OUTPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN7_ID,INPUT_PIN);
	}
	else if (SPI_ConfigParameter->MasterSlaveTypes == MASTER)
	{
		/******** Configure SPI Master Pins *********
			 * SS(PB4)   --> Output
			 * MOSI(PB5) --> Output
			 * MISO(PB6) --> Input
			 * SCK(PB7) --> Output
			 ********************************************/

			DIO_setupPinDirection(PORTB_ID,PIN4_ID,OUTPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN5_ID,OUTPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN6_ID,INPUT_PIN);
			DIO_setupPinDirection(PORTB_ID,PIN7_ID,OUTPUT_PIN);
	}

	/*set value of clock polarity & clock phase & Enable SPI Driver */
	SPCR = ( SPI_ConfigParameter->CLOCKPOLARITY << 3) | (SPI_ConfigParameter->CLOCKPHASE << 2 ) | (SPI_ConfigParameter->MasterSlaveTypes << 4)| (1<<SPE);
//
//	SPCR |= (1 << SPR1) | (1 << SPR0);  /* optional */



	
}






/*
 * Description :
 * Send the required data through SPI to the other SPI device.
 * In the same time data will be received from the other device.
 */
void SPI_sendByte(uint8_t data)
{
	/* Initiate the communication and send data by SPI */
		SPDR = data;

		/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
		while(BIT_IS_CLEAR(SPSR,SPIF)){}
}


uint8_t SPI_sendReceiveByte(uint8_t data)
{
	/* Initiate the communication and send data by SPI */
	SPDR = data;

	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(BIT_IS_CLEAR(SPSR,SPIF)){}

	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPDR;
}

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_sendString(const uint8_t *str)
{
	uint8_t i = 0;
	uint8_t received_data = 0;

	/* Send the whole string */
	while(str[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_receiveString(uint8_t *str)
{
	uint8_t i = 0;

	/* Receive the first byte */
	str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
}
