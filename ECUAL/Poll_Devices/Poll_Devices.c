/*
 * Poll_Devices.c
 *
 *  Created on: Dec 13, 2022
 *      Author: HESHAM
 */

#include "Poll_Devices.h"


float TC72_temperatureGetData(void)
{
	float temperature =0;
	TC72_temperatureRead(&temperature);
	return temperature;
}
