#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pirate.h"

static uint8_t shift_out[2] = { 0, 0 };

void shift_init(void) {
    gpio_set_function(SHIFT_EN, GPIO_FUNC_SIO);
    gpio_put(SHIFT_EN, 1); // active low
    gpio_set_dir(SHIFT_EN, GPIO_OUT);

    gpio_set_function(SHIFT_LATCH, GPIO_FUNC_SIO);
    gpio_put(SHIFT_LATCH, 0);
    gpio_set_dir(SHIFT_LATCH, GPIO_OUT);
}

void shift_output_enable(bool enable) {
    if (enable) {
        gpio_put(SHIFT_EN, 0); // active low, enable shift register outputs
    } else {
        gpio_put(SHIFT_EN, 1); // high, disable shift register outputs
    }
    busy_wait_us(5);
}

void shift_clear_set(uint16_t clear_bits, uint16_t set_bits) {
    extern uint8_t shift_out[2];
    spi_set_baudrate(BP_SPI_PORT, BP_SPI_SHIFT_SPEED); // 595s can't go full speed at low temperatures
    shift_out[1] &= ~((uint8_t)clear_bits);
    shift_out[0] &= ~((uint8_t)(clear_bits >> 8));
    shift_out[1] |= (uint8_t)set_bits;
    shift_out[0] |= (uint8_t)(set_bits >> 8);
    spi_write_blocking(BP_SPI_PORT, shift_out, 2);
    gpio_put(SHIFT_LATCH, 1);
    busy_wait_us(1);
    gpio_put(SHIFT_LATCH, 0);
    spi_set_baudrate(BP_SPI_PORT, BP_SPI_HIGH_SPEED);
}

