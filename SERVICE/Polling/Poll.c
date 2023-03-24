/*
 * Poll.c
 *
 *  Created on: Dec 11, 2022
 *      Author: HESHAM
 */

#include "Poll.h"
#include "../../ECUAL/Poll_DataClient/Poll_DataClient.h"
#include "../../ECUAL/Poll_Devices/Poll_Devices.h"

#include "../../ECUAL/LCD/LCD.h"

unsigned char Poll_Enable =1;/*variable responsible for enable and disable poll*/
unsigned long Poll_countTime =0; /*variable responsible for store time wanted to poll */
unsigned short int poll_count = 0;/*variable responsible for store number of counts needed for one poll*/


void POLL(void)
{
	if ( Poll_Enable && (!poll_count))
	{
		/*Here will put gets data for devices wanted and handling for this data*/
		float TC72_data =TC72_temperatureGetData();
		TC72_displayTemperature(TC72_data);
		Tc72_temperatureDataHandle(TC72_data);
	}
	poll_count++;
	poll_count = poll_count % Poll_countTime;
}

/*
* Description:
* function responsible for enable poll by set value of variable that check for it if Poll is enabled /disabled
*/
void POLL_start(void)
{
	Poll_Enable = 1;
}

/*
* Description:
* function responsible for enable poll by clear value of variable that check for it if Poll is enabled /disabled
*/
void POLL_stop(void)
{
	Poll_Enable = 0;
}

void POLL_setTime(unsigned long Poll_time)
{

	Poll_countTime = Poll_time /100;
}



