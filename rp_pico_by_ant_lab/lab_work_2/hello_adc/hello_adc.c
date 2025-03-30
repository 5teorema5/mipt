#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);

    while (1) {
        char cmd = getchar();
        if (cmd == 'a') {
            const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();
        // printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
        printf("%f\n", result * conversion_factor);
        sleep_ms(500);
        }
    }
}
