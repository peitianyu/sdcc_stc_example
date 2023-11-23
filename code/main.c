#include "gpio.h"
#include "delay.h"
#include "timer.h"
#include "uart.h"
#include "c_math.h"

static u16 g_1s = 0;
void main()
{
    gpio_init(3, 3, GPIO_PullUp);
    timer_init(0, 1000);   // 定时器0, 1kHz

    gpio_init(3, 0, GPIO_PullUp);
    gpio_init(3, 1, GPIO_PullUp);
    uart1_init();

    EA = 1;  							                                    

    while(1)
    {
        if(g_1s >= 1000){
            g_1s = 0;

            float float_val = 1.23; // 浮点数值
            u8* hex = float2hex(float_val);
            for (int i = 3; i >=0 ; i--) 
                print("%02X ", hex[i]);
            print("\n");

            gpio_toggle(P33);
        }
    }
}

INTERRUPT(timer_irq, 1)
{
    g_1s++;
}