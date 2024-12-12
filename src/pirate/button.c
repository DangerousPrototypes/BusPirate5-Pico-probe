#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pirate.h"
#include "pirate/button.h"


// poll the value of button button_id
bool button_get(uint8_t button_id) {
#if (BP_VER == 5)
    return gpio_get(EXT1);
#else
    return !gpio_get(EXT1);
#endif
}
// initialize all buttons
void button_init(void) {
    gpio_set_function(EXT1, GPIO_FUNC_SIO);
    gpio_set_dir(EXT1, GPIO_IN);
#if (BP_VER == 5)
    gpio_pull_down(EXT1);
#else
    gpio_pull_up(EXT1);
#endif
}
