#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "ili9341/ili9341.h"
#include "TimesNewRoman/TimesNewRoman.h"
#include "mathplot/mathplot.h"

int main()
{
    stdio_init_all();
    init_SPI();
    init_display();
    init_drawing();

    clear_buffer();
    enter_a_text("0123456789", 100, 100, get_buffer());
    enter_a_text("HUMIDITY: 27%", 80, 110, get_buffer());
    enter_a_text("100% MADE BY:\nLOKHMATOV ARSENIY\nDOLGOPRUDNY, 2025", 0, SCREEN_HEIGHT-30, get_buffer());
    struct CoordinatePlane plane = {plane.x=0, plane.y=SCREEN_HEIGHT-100, plane.w=SCREEN_WIDTH, plane.h=100};
    plot_axes(plane, get_buffer());
    display_buffer();
}
