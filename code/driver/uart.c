#include "uart.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void uart1_init(void)	//115200bps@24.000MHz
{
    SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0xCC;			//设置定时初始值
	TH1 = 0xFF;			//设置定时初始值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
    // ES = 1;             //使能串口中断
}
static void uart1_send_byte(u8 dat)
{
    SBUF = dat;
    while(!TI);
    TI = 0;
}

static void uart1_send_array(u8 *p, u8 len)
{
    while(len--) {
        uart1_send_byte(*p++);
    }
}

void print(char *p, ...)
{
    va_list ap;
    char buf[32];
    va_start(ap, p);
    vsprintf(buf, p, ap);
    va_end(ap);
    uart1_send_array(buf, strlen(buf));
}
