/*
 * app.h
 *
 *  Created on: Dec 9, 2022
 *      Author: HESHAM
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/TC72_temperature/TC72_temperature.h"
#include "../SERVICE/PollTimer/PollTimer.h"
#include "../SERVICE/Polling/Poll.h"
#include "../ECUAL/DC_motor/dc_motor.h"

void APP_init(void);


void APP_implement(void);


#endif /* APP_APP_H_ */
