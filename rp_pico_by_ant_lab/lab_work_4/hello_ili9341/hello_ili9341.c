#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "ili9341/ili9341.h"
#include "square-swarm/square-swarm.h"
#include "gradient/gradient.h"
#include "ant-lab/ant-lab.h"

int main()
{
    stdio_init_all();
    init_SPI();
    init_display();
    init_drawing();

    // rectangles flying
    uint32_t playerCount = 50;

    struct Square player[playerCount];

    for (int i = 0; i < playerCount; i++)
    {
        player[i].x = rand() % 209;
        player[i].y = rand() % 289;
        player[i].w = 15;
        player[i].h = 15;
        player[i].xVelocity = rand() % 4 - 2;
        player[i].yVelocity = rand() % 4 - 2;

        if (player[i].xVelocity == 0 && player[i].yVelocity == 0)
        {
            player[i].xVelocity = 3;
            player[i].yVelocity = 3;
        }

        player[i].color = rand() % 255;
    }

    while (true) {
        clear_buffer();
        handle_square_swarm(player, playerCount, get_buffer());
        display_buffer();
    }

    // gradient
    // uint16_t color_start = 200;
    // int size = SCREEN_HEIGHT;
    // uint16_t color[size];
    // memset(color, 0, sizeof(color));
    // for (int j = 0; j < size; j++) {
    //     color[j] = color_start + (j/30);
    // }
    // clear_buffer();
    // gradient_horizontal(get_buffer(), color, size);
    // display_buffer();

    // ant-lab logo
    // clear_buffer();
    // uint8_t* antlab = get_antlab_image_buffer();
    // display_external_buffer(antlab);
    // display_buffer();
    // sleep_ms(1000);
}
