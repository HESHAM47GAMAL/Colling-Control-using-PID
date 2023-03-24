/*
 * PollTimer.c
 *
 *  Created on: Dec 13, 2022
 *      Author: HESHAM
 */


#include "PollTimer.h"
#include "../Polling/Poll.h"
#include "../../MCUAL/TIMER1/TIMER1.h"
#include "../../ECUAL/LCD/LCD.h"
#include "../../MCUAL/DIO/DIO.h"
#include <avr/interrupt.h>
/*TIMER0_COMP_vect*/


ISR(TIMER1_COMPA_vect)
{

	PollTimer_callBack();

}

void PollTimer_start(void)
{
	TIMER1_startCTC();
}

void PollTimer_stop(void)
{
	TIMER1_stopCTC();
}

void PollTimer_enableInterrupt(void)
{
	TIMER1_enableInterrupt();
}

void PollTimer_disableInterrupt(void)
{
	TIMER1_disableInterrupt();
}

void PollTimer_callBack(void)
{
	POLL();
}

