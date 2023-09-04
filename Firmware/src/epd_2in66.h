#pragma once

void init(void);
void init_partial(void);
void wait_until_idle(void);

void display_frame(unsigned char *image, unsigned char *red_image, int size);
void sleep(void);