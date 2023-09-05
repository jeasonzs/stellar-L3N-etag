#include "epd_if.h"
#include "drivers.h"

#define EPD_RESET 	GPIO_PD4
#define EPD_DC 		GPIO_PD7
#define EPD_BUSY 	GPIO_PA1
#define EPD_CS		GPIO_PB4
#define EPD_CLK		GPIO_PB5
#define EPD_MOSI	GPIO_PB6
#define EPD_ENABLE	GPIO_PC5

_attribute_ram_code_ void epd_init(void)
{
    gpio_set_func(EPD_RESET, AS_GPIO);
    gpio_set_output_en(EPD_RESET, 1);
    gpio_setup_up_down_resistor(EPD_RESET, PM_PIN_PULLUP_1M);

    gpio_set_func(EPD_DC, AS_GPIO);
    gpio_set_output_en(EPD_DC, 1);
    gpio_setup_up_down_resistor(EPD_DC, PM_PIN_PULLUP_1M);

    gpio_set_func(EPD_BUSY, AS_GPIO);
    gpio_set_output_en(EPD_BUSY, 0);
    gpio_set_input_en(EPD_BUSY, 1);
    gpio_setup_up_down_resistor(EPD_BUSY, PM_PIN_PULLUP_1M);

    gpio_set_func(EPD_CS, AS_GPIO);
    gpio_set_output_en(EPD_CS, 1);
    gpio_setup_up_down_resistor(EPD_CS, PM_PIN_PULLUP_1M);

    gpio_set_func(EPD_CLK, AS_GPIO);
    gpio_set_output_en(EPD_CLK, 1);
    gpio_setup_up_down_resistor(EPD_CLK, PM_PIN_PULLUP_1M);

    gpio_set_func(EPD_MOSI, AS_GPIO);
    gpio_set_output_en(EPD_MOSI, 1);
    gpio_setup_up_down_resistor(EPD_MOSI, PM_PIN_PULLUP_1M);

    gpio_set_output_en(EPD_ENABLE, 0);
    gpio_set_input_en(EPD_ENABLE, 1);
    gpio_setup_up_down_resistor(EPD_ENABLE, PM_PIN_PULLUP_1M);
}

void epd_reset() {
    gpio_write(EPD_RESET, 0);
    WaitMs(10);
    gpio_write(EPD_RESET, 1);
}

void epd_set_power(unsigned int value) {
    gpio_write(EPD_ENABLE, value);
}

unsigned int epd_is_busy() {
    return gpio_read(EPD_BUSY);
}

void epd_mode_cmd() {
    gpio_write(EPD_DC, 0);
}

void epd_mode_data() {
    gpio_write(EPD_DC, 1);
}

_attribute_ram_code_ void epd_spi_write(unsigned char value)
{
    unsigned char i;
    gpio_write(EPD_CS, 0);
    WaitUs(10);
    for (i = 0; i < 8; i++)
    {
        gpio_write(EPD_CLK, 0);
        if (value & 0x80)
        {
            gpio_write(EPD_MOSI, 1);
        }
        else
        {
            gpio_write(EPD_MOSI, 0);
        }
        value = (value << 1);
        gpio_write(EPD_CLK, 1);
    }
    gpio_write(EPD_CS, 1);
}

_attribute_ram_code_ unsigned char epd_spi_read(void)
{
    unsigned char i;
    unsigned char value = 0;

    gpio_shutdown(EPD_MOSI);
    gpio_set_output_en(EPD_MOSI, 0);
    gpio_set_input_en(EPD_MOSI, 1);
    gpio_write(EPD_CS, 0);
    epd_mode_data();
    WaitUs(10);
    for (i = 0; i < 8; i++)
    {
        gpio_write(EPD_CLK, 0);
        gpio_write(EPD_CLK, 1);
        value <<= 1;
        if (gpio_read(EPD_MOSI) != 0)
        {
            value |= 1;
        }
    }
    gpio_set_output_en(EPD_MOSI, 1);
    gpio_set_input_en(EPD_MOSI, 0);
    gpio_write(EPD_CS, 1);
    return value;
}
