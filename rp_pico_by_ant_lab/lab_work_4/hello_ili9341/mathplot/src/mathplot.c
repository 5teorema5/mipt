#include "mathplot/mathplot.h"

#include "ili9341/ili9341.h"

uint8_t arr_v[30] = {
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0,
    0, 1, 1, 1, 0,
    0, 1, 1, 1, 0,
    1, 1, 1, 1, 1,
    };

uint8_t arr_h[30] = {
    1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0,
    1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0,
    1, 0, 0, 0, 0, 0,
    };

void plot_line_v(uint8_t x, uint8_t y, uint8_t l, uint8_t* buffer)
{
    for (int i = (y-l)*SCREEN_WIDTH*2; i < (SCREEN_WIDTH*y*2); i+=SCREEN_WIDTH*2)
    {
        for (int j = x * 2; j < (x * 2) + 1; j+=2)
        {
            buffer[i+j] = 100;
            buffer[i+j+1] = 100;
        }
    }

    int n = 0;
    for (int i = (y-l)*SCREEN_WIDTH*2; i < (SCREEN_WIDTH*(y-l)*2) + (6*SCREEN_WIDTH*2); i+=SCREEN_WIDTH*2)
    {
        for (int j = (x-2) * 2; j < ((x-2) * 2) + (5*2); j+=2)
        {
            if (arr_v[n]) {
                buffer[i+j] = 100;
                buffer[i+j+1] = 100;
            }
            n++;
        }
    }
}

void plot_line_h(uint8_t x, uint8_t y, uint8_t l, uint8_t* buffer)
{
    for (int i = y*SCREEN_WIDTH*2; i < (SCREEN_WIDTH*y*2) + 1; i+=SCREEN_WIDTH*2)
    {
        for (int j = x * 2; j < (x * 2) + (l*2); j+=2)
        {
            buffer[i+j] = 100;
            buffer[i+j+1] = 100;
        }
    }

    int n = 0;
    for (int i = (y-2)*SCREEN_WIDTH*2; i < (SCREEN_WIDTH*(y+2)*2) + 1; i+=SCREEN_WIDTH*2)
    {
        for (int j = (x+l-6) * 2; j < ((x+l) * 2); j+=2)
        {
            if (arr_h[n]) {
                buffer[i+j] = 100;
                buffer[i+j+1] = 100;
            }
            n++;
        }
    }
}

void plot_axes(struct CoordinatePlane plane, uint8_t* buffer)
{
    plot_line_h(plane.x + 10, plane.y + 10, plane.w - 20, buffer);
    plot_line_v(plane.x + 20, plane.y + 20, plane.h - 20, buffer);
}
