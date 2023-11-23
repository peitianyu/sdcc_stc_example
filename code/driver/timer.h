#ifndef __TIMER_H__
#define __TIMER_H__

#include "config.h"

#define     TLOAD(k)     (65536 - MAIN_Fosc/k)

// timer_id: 0, 1
#define timer_init(id, hz)                  					do      	\
{                                                                           \
	if(id == 0)			AUXR |= 0x80, TMOD &= 0xF0;                         \
	else if(id == 1)	AUXR |= 0x40, TMOD &= 0x0F;	                        \
	TL##id = TLOAD(hz);	   			                                        \
	TH##id = TLOAD(hz) >> 8;	   		                                    \
	TF##id = 0;																\
	TR##id = 1;       				                                        \
	ET##id = 1;       				                                        \
	EA = 1;  							                                    \
} while (0)

#endif // __TIMER_H__