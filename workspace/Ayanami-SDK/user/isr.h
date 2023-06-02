/*
 * isr.h
 *
 *  Created on: 2023Äê6ÔÂ1ÈÕ
 *      Author: 13164
 */

#ifndef USER_ISR_H_
#define USER_ISR_H_

#include <ayanami_common/aya_common_base_head.h>
#include <ayanami_common/aya_common_driver_head.h>

//Timer Interrupt handler

void Timer0IntHandler(void);
void Timer1IntHandler(void);
void Timer2IntHandler(void);
void Timer3IntHandler(void);
void Timer4IntHandler(void);
void Timer5IntHandler(void);


#endif /* USER_ISR_H_ */
