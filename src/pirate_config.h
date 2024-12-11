// Pin names for terminal and LCD display, in order
const char *hw_pin_label_ordered[] = {
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
    psu_init();
    //if(psu_enable(3.3, 0, true)) while(true);
}