
#include "app.h"

#include "drivers.h"

_attribute_ram_code_ void user_init_normal(void)
{                            // this will get executed one time after power up
    // random_generator_init(); // must
    // init_time();
    // init_ble();
    // init_flash();

}

_attribute_ram_code_ void user_init_deepRetn(void)
{ // after sleep this will get executed
    // blc_ll_initBasicMCU();
    // rf_set_power_level_index(RF_POWER_P3p01dBm);
    // blc_ll_recoverDeepRetention();
}

_attribute_ram_code_ void main_loop(void)
{
    // blt_sdk_main_loop();
    // handler_time();

}
