/*
 * Poll.h
 *
 *  Created on: Dec 11, 2022
 *      Author: HESHAM
 */

#ifndef SERVICE_POLLING_POLL_H_
#define SERVICE_POLLING_POLL_H_

void POLL_start(void);

void POLL_stop(void);

void POLL(void);

void POLL_setTime(unsigned long);

#endif /* SERVICE_POLLING_POLL_H_ */
