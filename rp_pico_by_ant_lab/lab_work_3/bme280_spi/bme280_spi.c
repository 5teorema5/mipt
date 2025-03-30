#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "bme280/bme280.h"

int main() {
    stdio_init_all();
    init_bme();

    int32_t humidity, pressure, temperature;

    while (1) {
        char cmd = getchar();
        if (cmd == 'a') {
            bme280_read_raw(&humidity, &pressure, &temperature);

            temperature = compensate_temp(temperature);
            pressure = compensate_pressure(pressure);
            humidity = compensate_humidity(humidity);
            printf("%.2f\n", humidity / 1024.0);
            printf("%d\n", pressure);
            printf("%.2f\n", temperature / 100.0);
    
            // printf("Humidity = %.2f%%\n", humidity / 1024.0);
            // printf("Pressure = %dPa\n", pressure);
            // printf("Temp. = %.2fC\n", temperature / 100.0);
    
            // sleep_ms(100);
        }
        else if (cmd = 'i') {
            indoor_navigation();
        }
        else if (cmd = 'n') {
            not_indoor_navigation();
        }
    }
}
