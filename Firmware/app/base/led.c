#include "led.h"

#include <stdint.h>

#include "drivers.h"

#define LED_BLUE	GPIO_PA7
#define LED_RED		GPIO_PD2
#define LED_GREEN	GPIO_PD3

_attribute_ram_code_ void init_led(void)
{
    gpio_setup_up_down_resistor(LED_BLUE, PM_PIN_PULLUP_1M);
    gpio_write(LED_BLUE, 1);
    gpio_set_func(LED_BLUE, AS_GPIO);
    gpio_set_output_en(LED_BLUE, 1);
    gpio_set_input_en(LED_BLUE, 0);

    gpio_write(LED_RED, 1);
    gpio_setup_up_down_resistor(LED_RED, PM_PIN_PULLUP_1M);
    gpio_set_func(LED_RED, AS_GPIO);
    gpio_set_output_en(LED_RED, 1);
    gpio_set_input_en(LED_RED, 0);

    gpio_setup_up_down_resistor(LED_GREEN, PM_PIN_PULLUP_1M);
    gpio_write(LED_GREEN, 1);
    gpio_set_func(LED_GREEN, AS_GPIO);
    gpio_set_output_en(LED_GREEN, 1);
    gpio_set_input_en(LED_GREEN, 0);
}

_attribute_ram_code_ void set_led_color(uint8_t color)
{
    switch (color)
    {
    case 1:
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 0);
        gpio_write(LED_GREEN, 1);
        break;
    case 2:
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 0);
        break;
    case 3:
        gpio_write(LED_BLUE, 0);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 1);
        break;
    default:
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 1);
        break;
    }
}
