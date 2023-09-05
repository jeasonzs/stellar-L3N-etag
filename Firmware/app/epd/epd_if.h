#pragma once

void epd_init(void);

void epd_reset();
void epd_set_power(unsigned int value);
unsigned int epd_is_busy();

void epd_mode_cmd();
void epd_mode_data();

void epd_spi_write(unsigned char value);
unsigned char epd_spi_read(void);
