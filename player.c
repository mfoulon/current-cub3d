#include "cub3d.h"

static void     init_lat(t_player *player, t_data *data)
{
    if (data->map.start_dir == NORTH)
	{
		player->dx = 0;
		player->dy = -1;
		player->px = 0.66;
		player->py = 0;
	}
	else
	{
		player->dx = 0;
		player->dy = 1;
		player->px = -0.66;
		player->py = 0;
	}
}

static void     init_long(t_player *player, t_data *data)
{
    if (data->map.start_dir == EAST)
	{
		player->dx = 1;
		player->dy = 0;
		player->px = 0;
		player->py = 0.66;
	}
	else
	{
		player->dx = -1;
		player->dy = 0;
		player->px = 0;
		player->py = -0.66;
	}
}

void    init_player(t_player *player, t_data *data)
{
    player->y = data->map.start_row + 0.5;
    player->x = data->map.start_col + 0.5;
    player->is_moving = false;
    if (data->map.start_dir == NORTH || data->map.start_dir == SOUTH)
        init_lat(player, data);
    else
        init_long(player, data);
}