#include "cub3d.h"

void    draw_tile(int x, int y, int color, t_game *data)
{
    int tile_width;
    int tile_height;
    int i;
    int j;

    tile_width = WINDOW_WIDTH / data->map->width;
    tile_height = WINDOW_HEIGHT / data->map->height;
    i = x * tile_width;
    while (i < tile_width * (x + 1))
    {
        j = 0;
        while (j < tile_height * (y + 1))
        {
            img_pix_put(data->img, i, j, color);
            j++;
        }
        i++;
    }
}

void    draw_map(t_game *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map->width)
    {
        j = 0;
        while (j < data->map->height)
        {
            if (data->map->map[i][j] == '1')
                draw_tile(i, j, BLACK_PIXEL, data);
            else if (data->map->map[i][j] == 0)
                draw_tile(i, j, WHITE_PIXEL, data);
            else
                draw_tile(i, j, RED_PIXEL, data);
            j++;
        }
        i++;
    }
}