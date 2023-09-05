OUT_DIR += /epd /base /ble

OBJS += \
$(OUT_PATH)/base/battery.o \
$(OUT_PATH)/base/etime.o \
$(OUT_PATH)/base/flash.o \
$(OUT_PATH)/base/led.o \
$(OUT_PATH)/base/uart.o \
$(OUT_PATH)/epd/epd_if.o \
$(OUT_PATH)/epd/epd_2in66.o \
$(OUT_PATH)/app.o \
$(OUT_PATH)/main.o

# OBJS += \
# $(OUT_PATH)/app.o \
# $(OUT_PATH)/app_att.o \
# $(OUT_PATH)/battery.o \
# $(OUT_PATH)/ble.o \
# $(OUT_PATH)/epd_ble_service.o \
# $(OUT_PATH)/cmd_parser.o \
# $(OUT_PATH)/flash.o \
# $(OUT_PATH)/etime.o \
# $(OUT_PATH)/epd_spi.o \
# $(OUT_PATH)/old_app.o \
# $(OUT_PATH)/epd_bwr_266.o \
# $(OUT_PATH)/ota.o \
# $(OUT_PATH)/led.o \
# $(OUT_PATH)/uart.o \
# $(OUT_PATH)/tiffg4.o \
# $(OUT_PATH)/one_bit_display.o \
# $(OUT_PATH)/epd/epd_if.o \
# $(OUT_PATH)/epd/epd_2in66.o \
# $(OUT_PATH)/main.o

# Each subdirectory must supply rules for building sources it contributes
$(OUT_PATH)/%.o: ./app/%.c
	@echo 'Building file: $<'
	@$(TC32_COMPILER_PATH)tc32-elf-gcc $(GCC_FLAGS) $(INCLUDE_PATHS) -c -o"$@" "$<"
