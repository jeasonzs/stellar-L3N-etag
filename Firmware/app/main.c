#include "app.h"
#include "base/led.h"
#include "base/uart.h"

#include "stack/ble/ble.h"

_attribute_ram_code_ __attribute__((optimize("-Os"))) void irq_handler(void)
{
	irq_blt_sdk_handler();
}

_attribute_ram_code_ int main (void)    //must run in ramcode
{
	blc_pm_select_internal_32k_crystal();
	cpu_wakeup_init();
	int deepRetWakeUp = pm_is_MCU_deepRetentionWakeup();  //MCU deep retention wakeUp
	rf_drv_init(RF_MODE_BLE_1M);
	gpio_init( !deepRetWakeUp );  //analog resistance will keep available in deepSleep mode, so no need initialize again
#if (CLOCK_SYS_CLOCK_HZ == 16000000)
	clock_init(SYS_CLK_16M_Crystal);
#elif (CLOCK_SYS_CLOCK_HZ == 24000000)
	clock_init(SYS_CLK_24M_Crystal);
#endif
	blc_app_loadCustomizedParameters();
	
    init_led();
	init_uart();
		
	if( deepRetWakeUp ){
		user_init_deepRetn ();
		printf("\r\n\r\n\r\nBooting\r\n\r\n\r\n\r\n");
	}
	else{
		printf("\r\n\r\n\r\nBooting\r\n\r\n\r\n\r\n");
		user_init_normal ();
	}	
    irq_enable();
	while (1) {
		main_loop ();
	}
}

