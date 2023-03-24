/*
 * Poll_DataClient.c
 *
 *  Created on: Dec 13, 2022
 *      Author: HESHAM
 */


#include "Poll_DataClient.h"
#include "../DC_motor/dc_motor.h"
#include "../LCD/LCD.h"

#define KP  0.1f
#define KI  0.01f
float integral =0;

void Tc72_temperatureDataHandle(float temperature)
{
	float current_temperature = temperature;
	float target_temperature = 30;

	float error =  current_temperature - target_temperature;
	integral = integral + (error);
	int PWM_signal = (KP * error*10) +(KI * integral*10);
	if(PWM_signal > 186 )
	{
		PWM_signal = 186;
	}
	else if(PWM_signal  < 0)
	{
		PWM_signal = 0;
	}

	DcMotor_Rotate(CW,PWM_signal);
	LCD_moveCursor(1,3);
	LCD_intToString(PWM_signal);


}
