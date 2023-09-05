#pragma once

typedef struct {
    unsigned int width;
    unsigned int height;
    void (*init)(void);
    void (*init_partial)(void);
    int (*wait_idle)(unsigned int);
    void (*load_bw_image)(unsigned char *);
    void (*load_red_image)(unsigned char *);
    void (*display)(void);
} EPD;

EPD* create_epd_2in66();
