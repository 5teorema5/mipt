#pragma once

#include <stdint.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>

struct TimeNewRoman_font
{
    uint8_t w;
    uint8_t h;
    uint8_t *tnr;
};

uint16_t enter_a_letter(char letter, uint16_t x, uint16_t y, uint8_t* buffer);

void enter_a_text(char text[], uint16_t x, uint16_t y, uint8_t* buffer);

void letter_to_buffer(struct TimeNewRoman_font letter, uint16_t x, uint16_t y, uint8_t* buffer);
