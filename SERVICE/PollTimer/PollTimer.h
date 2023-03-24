/*
 * PollTimer.h
 *
 *  Created on: Dec 13, 2022
 *      Author: HESHAM
 */

#ifndef POLLTIMER_H_
#define POLLTIMER_H_

void PollTimer_start(void);

void PollTimer_stop(void);

void PollTimer_enableInterrupt(void);

void PollTimer_disableInterrupt(void);

void PollTimer_callBack(void);

#endif /* SERVICE_POLLTIMER_POLLTIMER_H_ */
