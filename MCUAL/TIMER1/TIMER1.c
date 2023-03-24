/*
 * TIMER.h
 *
 *  Created on: Dec 13, 2022
 *      Author: HESHAM
 */
#include "../../utilities/std_types.h"
#include "TIMER1.h"

void TIMER1_startCTC(void)
{
	TCNT1 = 0;

	OCR1A = 391;



	TCCR1A = (1<<FOC1A);
	/*FCPU/256
	 * number of clocks per 100ms is 390.6*/
	TCCR1B = (1<<WGM12) | (4<<CS10);

}

void TIMER1_stopCTC(void)
{
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);
}

void TIMER1_enableInterrupt(void)
{
	/*Enable timer interrupt*/
	TIMSK |= (1<<OCIE1A);
	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}

void TIMER1_disableInterrupt(void)
{
	TIMSK &= ~(1<<OCIE1A);
}
