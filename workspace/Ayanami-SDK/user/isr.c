/*
 * isr.c
 *
 *  Created on: 2023Äê6ÔÂ1ÈÕ
 *      Author: 13164
 */
#include "isr.h"

void Timer0IntHandler(void)
{
    MAP_TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);


}

void Timer1IntHandler(void)
{
    MAP_TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

}

void Timer2IntHandler(void)
{
    MAP_TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

}

void Timer3IntHandler(void)
{
    MAP_TimerIntClear(TIMER3_BASE, TIMER_TIMA_TIMEOUT);

}

void Timer4IntHandler(void)
{
    MAP_TimerIntClear(TIMER4_BASE, TIMER_TIMA_TIMEOUT);

}

void Timer5IntHandler(void)
{
    MAP_TimerIntClear(TIMER5_BASE, TIMER_TIMA_TIMEOUT);

}
