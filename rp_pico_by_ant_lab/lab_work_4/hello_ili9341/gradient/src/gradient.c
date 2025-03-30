#include "gradient/gradient.h"

#include "ili9341/ili9341.h"

void gradient_horizontal(uint8_t* buffer, uint16_t* color, int size) {
    uint8_t n = 0;
    for (int j = 0; j < size; j++) {
        for (unsigned int i = 0; i < size*2; i+=2) {
            buffer[size*2*j + i] = color[n] % 255;
            buffer[size*2*j + i + 1] = color[n] % 255;
        }
        n++;
    }
}
