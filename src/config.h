#ifndef		__CONFIG_H
#define		__CONFIG_H

#define MAIN_Fosc		24000000L	//定义主时钟

#include "stc8g1k08a.h"
#include "intrins.h"


typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;

#define	TRUE	1
#define	FALSE	0

#define     I2C_P33_P32     0x00
#define     I2C_P55_P54     0x10

#endif
