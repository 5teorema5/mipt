#pragma once

#include <stdint.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>

struct CoordinatePlane
{
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
};

void plot_line_h(uint8_t x, uint8_t y, uint8_t l, uint8_t* buffer);

void plot_line_v(uint8_t x, uint8_t y, uint8_t l, uint8_t* buffer);

void plot_axes(struct CoordinatePlane plane, uint8_t* buffer);

