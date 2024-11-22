#include "cub3d.h"
#include <stdio.h>

bool	ft_init(t_data *data)
{
	data->map.string_map = NULL;
	data->map.map = NULL;
	data->map.int_map = NULL;
	data->map.floor_hex = -1;
	data->map.ceiling_hex = -1;
	data->map.index = 'a';
	data->map.start_row = 0;
	data->map.start_col = 0;
	data->map.str_index = 0;
	data->map.offset = 0;
	data->fd = -1;
	while (++data->fd < 5)
	{
		data->texture_buffer[data->fd] = NULL;
		data->map.path_texture[data->fd] = NULL;
	}
	data->win_ptr = NULL;
	data->fd = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_error(EX11), false);
	return (true);
}

void    init_keys(t_keys *keys)
{
    keys->forward = false;
    keys->backward = false;
    keys->left = false;
    keys->right = false;
}

int main(int ac, char *av[])
{
    t_data  data;

    (void)av;
    if (ac != 2)
        return (ft_error(EIO), 1);
    if (!ft_init(&data))
        return (1);
    if (!fill_and_parse_data(av, &data))
        return (free_data(&data), 1); // error here -> reslove map : map is not solvable ????
    init_player(&data.player, &data);
    init_keys(&data.keys);
    init_window(&data);
    free_data(&data);
    return (0);
}