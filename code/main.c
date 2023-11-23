#include "gpio.h"
#include "delay.h"
#include "timer.h"
#include "uart.h"

static u16 g_1s = 0;
void main()
{
    gpio_init(3, 3, GPIO_PullUp);
    timer_init(0, 1000);   // 定时器0, 1kHz
    uart1_init();

    print("hello world\n");

    while(1)
    {
        if(g_1s >= 1000){
            g_1s = 0;
            gpio_toggle(P33);

            print("hello world\n");
        }
    }
}

INTERRUPT(timer_irq, 1)
{
    g_1s++;
}