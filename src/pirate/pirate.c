#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "pirate.h"
#include "shift.h"
#include "pullup.h"
#include "bio.h"
#include "lcd.h"
#include "display/display.h"
#include "pirate_config.h"

void pirate_init(void){

    bio_init();

    // setup SPI0 for on board peripherals
    spi_init(BP_SPI_PORT, BP_SPI_HIGH_SPEED);
    gpio_set_function(BP_SPI_CDI, GPIO_FUNC_SPI);
    gpio_set_function(BP_SPI_CLK, GPIO_FUNC_SPI);
    gpio_set_function(BP_SPI_CDO, GPIO_FUNC_SPI);

    #if (BP_VER == 5 || BP_VER == XL5)
        shift_init();
    #endif
    // LCD pin init
    lcd_init();

    // ADC pin init
    //amux_init();
    adc_init();
    adc_gpio_init(AMUX_OUT);
    adc_gpio_init(CURRENT_SENSE);

    // TF flash card CS pin init
    //storage_init();
    // Output Pins
    gpio_set_function(FLASH_STORAGE_CS, GPIO_FUNC_SIO);
    gpio_put(FLASH_STORAGE_CS, 1);
    gpio_set_dir(FLASH_STORAGE_CS, GPIO_OUT);    

    // initial pin states
    #if (BP_VER == 5 || BP_VER == XL5)
        // configure the defaults for shift register attached hardware
        shift_clear_set(CURRENT_EN_OVERRIDE, (AMUX_S3 | AMUX_S1 | DISPLAY_RESET | CURRENT_EN));
    #endif

    pullup_init();

#if (BP_VER == 5 || BP_VER == XL5)
    // enable shift register outputs, 
    //also enabled level translator so don't do RGB LEDs before here!
    shift_output_enable(true); 
#endif    

    lcd_reset();
    lcd_configure();
    lcd_backlight_enable(true);

    ui_lcd_update(hw_pin_label_ordered, func_pin_label_ordered, direction_pin_label_ordered);
}