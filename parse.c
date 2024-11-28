#include "cub3d.h"

static bool	find_start(t_map *map, char **copy_map)
{
	char	**start;
	int		i;

	start = ft_split("N S W E", ' ');
	if (start == NULL)
		return (false);
	i = -1;
	while (copy_map[++i] != NULL)
	{
		if (ft_strchr_array(start, copy_map[i]) != -1)
		{
			map->start_row = i;
			map->start_col = ft_strchr_array(start, map->map[i]);
		}
	}
	return (free_array(start, 5), true);
}

static bool     to_int_map(t_map *map)
{
    int i;
    int j;

    i = -1;
    map->int_map = malloc(map->height * sizeof(int *));
    if (map->int_map == NULL)
        return (false);
    i = -1;
    while (++i < map->height)
    {
        map->int_map[i] = malloc((map->width + map->offset) * sizeof(int));
        if (map->int_map[i] == NULL)
            return (free_void_array((void **)map->int_map, i), map->int_map = NULL, false);
        j = -1;
        while (map->map[i][++j])
        {
            if (ft_strchr("01", map->map[i][j]))
                map->int_map[i][j] = map->map[i][j] - '0';
            else
                map->int_map[i][j] = 0;
        }   
    }
    return (true);
}

static bool     parse_args(t_data *data)
{
    if (data->map.floor_hex == -1 || data->map.ceiling_hex == -1)
        return (false);
    if (data->map.path_texture[NORTH] == NULL
            || data->map.path_texture[SOUTH] == NULL
            || data->map.path_texture[WEST] == NULL
            || data->map.path_texture[EAST] == NULL)
        return (false);
    return (true);
}

static bool     parse_map(t_data *data, t_map *map)
{
    char    **copy;
    int     i;

    i = -1;
    copy = ft_calloc(map->height + 1, sizeof(char *));
    if (copy == NULL)
        return (false);
    while (++i < map->height)
    {
        copy[i] = ft_strdup(map->map[i]);
        if (copy[i] == NULL)
            return (free_array(copy, i), false);
    }
    if (!find_start(map, copy))
        return (free_array(copy, -1), false);
    (void)data;
    // if (!resolve_map(data, copy))   //err here or in move functions
    //     return (free_array(copy, -1), false);
    return (free_array(copy, -1), resize_map(map, false));
}

bool    fill_and_parse_data(char *av[], t_data *data)
{
    if (av[1][ft_strlen(av[1]) - 3] != 'c'
		|| av[1][ft_strlen(av[1]) - 2] != 'u'
		|| av[1][ft_strlen(av[1]) - 1] != 'b'
		|| av[1][ft_strlen(av[1]) - 4] != '.'
		|| ft_strlen(av[1]) < 5)
		return (ft_error(EFILE), false);
    data->fd = open(av[1], O_RDONLY);
    if (data->fd <= 0)
        return (ft_error(ENOENT), false);
    if (ft_read(&data->map.string_map, data->fd) <= 1)
        return (ft_error(EFILE), false);
    if (data->map.string_map == NULL)
        return (ft_error(EMAP), false);
    if (!fill_map_config(&data->map))
        return (ft_error(ETXTUR), false);
    if (!parse_args(data))
        return (ft_error(ETXTUR), false);
    if (!init_map(&data->map) || !parse_map(data, &data->map)
            || !to_int_map(&data->map))
        return (ft_error(EMAP), false); //here from parse map
    if (!load_textures(data))
        return (ft_error(ETXTUR), false);
    return (true);
}