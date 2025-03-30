#include "square-swarm/square-swarm.h"

#include "ili9341/ili9341.h"

static void inline draw_rectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color, uint8_t* buffer)
{
    for (int i = y * SCREEN_WIDTH * 2; i < (SCREEN_WIDTH * y * 2) + (h * SCREEN_WIDTH * 2); i+=SCREEN_WIDTH * 2)
    {
        for (int j = x * 2; j < (x * 2) + (w * 2); j+=2)
        {
            buffer[i+j] = color;
            buffer[i+j+1] = color;
        }
    }
}

void update_players(struct Square player[], uint32_t playerCount)
{
    for (int i = 0; i < playerCount; i++)
        {
            player[i].x += player[i].xVelocity;
            player[i].y += player[i].yVelocity;
            
            if (player[i].x <= 0)
            {
                player[i].x = 0;
                player[i].xVelocity = -player[i].xVelocity;
            }

            if (player[i].x >= SCREEN_WIDTH - player[i].w)
            {
                player[i].x = SCREEN_WIDTH - player[i].w;
                player[i].xVelocity = -player[i].xVelocity;
            }

            if (player[i].y <= 0)
            {
                player[i].y = 0;
                player[i].yVelocity = -player[i].yVelocity;
            }

            if (player[i].y >= SCREEN_HEIGHT - player[i].h)
            {
                player[i].y = SCREEN_HEIGHT - player[i].h;
                player[i].yVelocity = -player[i].yVelocity;
            }
        }
}

void handle_square_swarm(struct Square player[], uint32_t playerCount, uint8_t* buffer)
{
    update_players(player, playerCount);

    for (int i = 0; i < playerCount; i++)
    {
        draw_rectangle(player[i].x, player[i].y, player[i].w, player[i].h, player[i].color, buffer);
    }
}
