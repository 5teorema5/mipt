#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "ili9341/ili9341.h"
#include "TimesNewRoman/TimesNewRoman.h"
#include "bme280/bme280.h"

int main()
{
    stdio_init_all();
    init_SPI();
    init_display();
    init_drawing();
    gpio_put(13, 1);

    init_bme();
    gpio_put(17, 1);

    int32_t humidity, pressure, temperature;
    char h[10], p[10], t[10];
    while (1) {
        gpio_put(17, 0);
        bme280_read_raw(&humidity, &pressure, &temperature);

        temperature = compensate_temp(temperature);
        pressure = compensate_pressure(pressure);
        humidity = compensate_humidity(humidity);
    
        snprintf(h, sizeof h, "%.2f", humidity / 1024.0);
        snprintf(p, sizeof p, "%d", pressure);
        snprintf(t, sizeof t, "%.2f", temperature / 100.0);
        gpio_put(17, 1);
    
        gpio_put(13, 0);
        clear_buffer();
        enter_a_text("100% MADE BY:\nLOKHMATOV ARSENIY\nDOLGOPRUDNY, 2025", 0, SCREEN_HEIGHT-30, get_buffer());
        enter_a_text("TEMPERATURE: \n\nPRESSURE: \n\nHUMIDITY: ", 0, 10, get_buffer());
        enter_a_text(t, 110, 10, get_buffer());
        enter_a_text(p, 110, 30, get_buffer());
        enter_a_text(h, 110, 50, get_buffer());
        enter_a_text("C", 150, 10, get_buffer());
        enter_a_text("PA", 150, 30, get_buffer());
        enter_a_text("%", 150, 50, get_buffer());

        display_buffer();
        gpio_put(13, 1);
    }
}
