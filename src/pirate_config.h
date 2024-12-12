// Pin names for terminal and LCD display, in order
const char *hw_pin_label_ordered_3v3[] = {
    "3.3V",
    "IO0",
    "IO1",
    "IO2",
    "IO3",
    "IO4",
    "IO5",
    "IO6",
    "IO7",
    "GND"
};

const char *hw_pin_label_ordered_vin[] = {
    "Vin",
    "IO0",
    "IO1",
    "IO2",
    "IO3",
    "IO4",
    "IO5",
    "IO6",
    "IO7",
    "GND"
};

const char *func_pin_label_ordered[] = {
    "PicoProbe",
    "SCLK",
    "-",
    "-",
    "-",
    "UTX",
    "URX",
    "-",
    "SDIO",
    "GND"
};

const char *direction_pin_label_ordered[]={
    "",
    "->",
    "",
    "",
    "",
    "->",
    "<-",
    "",
    "<->",
    "",
};

static inline void pirate_options_init(void){
    #include "pirate/psu.h"
    #include "pirate/button.h"
    if(!button_get(0)){
        ui_lcd_update(hw_pin_label_ordered_3v3, func_pin_label_ordered, direction_pin_label_ordered);
        psu_enable(3.3, 0, true);
    }else{
        ui_lcd_update(hw_pin_label_ordered_vin, func_pin_label_ordered, direction_pin_label_ordered);
    }
    #include "pirate/pirate.h"
    #include "pirate/bio.h"
    #include "board_buspirate5_config.h"
    //configure buffer directions
    bio_set_buffer_dir(PROBE_UART_TX, true);
    bio_set_buffer_dir(PROBE_UART_RX, false);   
}