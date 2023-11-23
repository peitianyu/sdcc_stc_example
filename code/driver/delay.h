#ifndef __DELAY_H__
#define __DELAY_H__

#include "config.h"

#define delay_ms(time) do                                                       \
{         																		\
	u8 ms = time;																\
    u16 i;                                                                      \
    do {                                                                        \
        i = MAIN_Fosc / 9000;                                                   \
        while (--i);                                                            \
    } while (--ms);                                                             \
} while(0)

#endif // __DELAY_H__