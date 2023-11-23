#include "gpio.h"
#include "delay.h"

void main()
{
    gpio_init(5, 4, GPIO_OUT_UP);

    while(1)
    {
		gpio_toggle(P54);
        delay_ms(1000);
    }
}

