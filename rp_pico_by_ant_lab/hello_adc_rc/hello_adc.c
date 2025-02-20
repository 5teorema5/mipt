/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("ADC Example, measuring GPIO26\n");

    adc_init();

    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
    gpio_init(27);
    gpio_set_dir(27, GPIO_OUT);

    while (1) {
        char cmd = getchar();
        if (cmd == 'e') {
            gpio_put(27, 1);
            const float conversion_factor = 3.3f / (1 << 12);
            uint16_t result = adc_read();
            printf("%f\n", result * conversion_factor);
            sleep_ms(500);
        }
        else if (cmd == 'd') {
            gpio_put(27, 0);
            const float conversion_factor = 3.3f / (1 << 12);
            uint16_t result = adc_read();
            printf("%f\n", result * conversion_factor);
            sleep_ms(500);
        }
    }
}
