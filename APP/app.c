/*
 * app.c
 *
 *  Created on: Dec 9, 2022
 *      Author: HESHAM
 */


#include "app.h"

#include "../MCUAL/DIO/DIO.h"

void APP_init(void)
{
	/*use user custom data type to set it with configuration for Timer 0*/
//	Timer0_ConfigType timer0_config_var ={NORMAL_MODE,F_CPU_1024};
//	/*init timer */
//
//	TIMER0_init(&timer0_config_var);

	/*init LCD*/
	LCD_init();
	LCD_clearScreen();

	DcMotor_Init();

	/*use user custom data type to set it with configuration for SPI*/
	SPI_configType  spi_config_var = {MASTER,IDLE_LOW,SHIFT_SAMPLE_DATA};

	/*init SPI*/
	SPI_init(&spi_config_var);



	/*init TC72 temperature sensro*/

	TC72_init(CONTINOUS_TEMP_CONVERSION);
	_delay_ms(150);

	PollTimer_start();

	PollTimer_enableInterrupt();

	POLL_setTime(500);

	POLL_start();

	DIO_setupPinDirection(PORTA_ID,PIN0_ID,OUTPUT_PIN);
	TIMSK |= (1<<OCIE1A);
		SREG  |= (1<<7);

}


void APP_implement(void)
{
	/*create signed short int variable to store temperature value on it */


	while(1)
	{
//		TC72_readRegister(MSB_TEMPERATURE_READ_ADDRESS,&temperature);

//		LCD_clearScreen();
//		count_app++;
//		LCD_intToString(count_app);
//
//		_delay_ms(300);
//		DcMotor_Rotate(A_CW,88);



//		POLL();
	}

}

