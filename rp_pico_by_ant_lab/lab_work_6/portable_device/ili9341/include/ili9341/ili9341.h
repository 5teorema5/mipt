#pragma once

#include <stdint.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
#define SCREEN_TOTAL_PIXELS SCREEN_WIDTH * SCREEN_HEIGHT
#define BUFFER_SIZE SCREEN_TOTAL_PIXELS * 2

void init_SPI(void);
void init_display(void);
void init_drawing(void);

void clear_buffer();
void display_buffer();
void display_external_buffer(uint8_t* external_buffer);

uint8_t* get_buffer(void);
