 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for DC_motor driver
 *
 * Author: Mohab Hisham
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "../../MCUAL/DIO/DIO.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



/*
 * Description:
 *
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 *
 *
 * Input: none
 *
 *
 * Return: none
 * */


void DcMotor_Init(void)
{
	/* configure pin PC0 and PC1 as output pins */
	DIO_setupPinDirection(PORTB_ID, PIN1_ID, OUTPUT_PIN);
	DIO_setupPinDirection(PORTB_ID, PIN2_ID, OUTPUT_PIN);

	/* Motor is stop at the beginning */
	DIO_writePin(PORTB_ID,PIN1_ID,0);
	DIO_writePin(PORTB_ID,PIN2_ID,0);
}


/*
 * Description:
 *
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *
 * Send the required duty cycle to the PWM driver based on the required speed value.
 *
 *
 * Inputs:
 *
 * state: The required DC Motor state, it should be CW or A-CW or stop. DcMotor_State data type should be declared as enum or uint8.
 *
 * speed: decimal value for the required motor speed, it should be from 0 → 100. For example, if the input is 50, The motor should rotate with 50% of its maximum speed.
 *
 *
 * Return: none
 * */

void DcMotor_Rotate(DcMotor_State state,uint8_t speed)
{
	/* initialize timer0 PWM with wanted compare value*/
	PWM_Timer0_Start(speed);

	/* PB0:PB1 = 00  rotation Stop
	 * PB0:PB1 = 01  rotate anti clockwise
	 * PB0:PB1 = 00  rotate clockwise
	 * */

	if(state == CW){
		DIO_writePin(PORTB_ID,PIN1_ID,0);
		DIO_writePin(PORTB_ID,PIN2_ID,1);
	}
	else if(state == A_CW){
		DIO_writePin(PORTB_ID,PIN1_ID,1);
		DIO_writePin(PORTB_ID,PIN2_ID,0);
	}
	else{
		DIO_writePin(PORTB_ID,PIN1_ID,0);
		DIO_writePin(PORTB_ID,PIN2_ID,0);
	}


}
