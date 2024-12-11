#include <stdio.h>
#include "pico/stdlib.h"
#include "pirate.h"
#include "hardware/gpio.h"
#include "bio.h"

void bio_init(void) {
    // setup the buffer IO and DIRection pins
    for (uint8_t i = 0; i < 8; i++) {
        //pin direction
        //gpio_set_inover(bio2bufiopin[i], GPIO_OVERRIDE_NORMAL);
        //gpio_set_outover(bio2bufiopin[i], GPIO_OVERRIDE_NORMAL);
        gpio_set_drive_strength(i+8, GPIO_DRIVE_STRENGTH_2MA);
        gpio_set_dir(i+8, GPIO_IN);
        gpio_set_function(i+8, GPIO_FUNC_SIO);
        //buffer
        gpio_put(i, BUFDIR_INPUT);
        gpio_set_dir(i, GPIO_OUT);
        gpio_set_function(i, GPIO_FUNC_SIO);
    }
} 

void bio_set_dir(uint8_t bio, bool dir) {
    //making some big assumption here that are currently true
    //could blow up on us later though
    if(bio < 8) {
        return;
    }else if(bio < 16) {
        if(dir) {
            // first set the buffer to output
            gpio_put(bio-8, BUFDIR_OUTPUT);
            // now set pin to output
            gpio_set_dir(bio, GPIO_OUT);
        } else {
            // first set the pin to input
            gpio_set_dir(bio, GPIO_IN);
            // now set buffer to input
            gpio_put(bio-8, BUFDIR_INPUT);
        }
    }else{
        gpio_set_dir(bio, dir);
    }
}

void bio_set_buffer_dir(uint8_t bio, bool dir) {
    gpio_put(bio-8, dir);
}
