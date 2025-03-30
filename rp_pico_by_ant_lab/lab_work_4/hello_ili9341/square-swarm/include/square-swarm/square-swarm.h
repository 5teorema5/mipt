#pragma once

#include <stdint.h>

struct Square
{
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
    int8_t xVelocity;
    int8_t yVelocity;
    uint8_t color;
};

void handle_square_swarm(struct Square player[], uint32_t playerCount, uint8_t* buffer);
