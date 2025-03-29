#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pico/stdlib.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif

int pico_led_init(void) {
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
}

void pico_set_led(bool led_on) {
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
}

static void read_register(uint8_t *mem_location) {
    uint8_t byte = *mem_location;
    printf("0x%p -> 0x%X", mem_location, byte);
}

int main() {
    stdio_init_all();

    int rc = pico_led_init();
    hard_assert(rc == PICO_OK);

    while (true) {
        char cmd = getchar();
        if (cmd == 'e') {
            pico_set_led(true);
        }
        else if (cmd == 'd') {
            pico_set_led(false);
        }
        else if (cmd == 'r') {
            char mem_char[10];
            for (int i = 0; i < 10; i++) {
                mem_char[i] = getchar();
            }
            char *endptr;
            unsigned long mem_long = strtoul(mem_char, &endptr, 16);
            uint8_t *mem_loc = (uint8_t *)mem_long;
            read_register(mem_loc);
        }
    }
}
