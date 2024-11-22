#include "cub3d.h"

static void ft_fill(char *line, t_map *map);
static long ft_char_to_rgb(char *s);


static long ft_char_to_rgb(char *s)
{
    char    **split;
    int     *rgb_array;
    long    rgb;

    split = ft_split(s, ',');
    if (split == NULL)
        return (-1);
    if (is_valid_rgb(split) == false)
        return (free_array(split, -1), -1);
    rgb_array = malloc(sizeof(int) * 3);
    if (rgb_array == NULL)
        return (free_array(split, -1), -1);
    rgb_array[0] = ft_atoi(split[0]);
    rgb_array[1] = ft_atoi(split[1]);
    rgb_array[2] = ft_atoi(split[2]);
    free_array(split, -1);
    if (rgb_array[0] < 0 || rgb_array[0] > 255 || rgb_array[1] < 0
        || rgb_array[1] > 255 || rgb_array[2] < 0 || rgb_array[2] > 255)
        return (free(rgb_array), -1);
    rgb = (rgb_array[0] << 16) + (rgb_array[1] << 8) + rgb_array[2];
	return (free(rgb_array), rgb);
}

static void ft_fill(char *line, t_map *map)
{
    char *parsed_line;

    if (line == NULL)
        return ;
    if (ft_strchr(line, 'C') || ft_strchr(line, 'F'))
        parsed_line = ft_strtrim(line + 2, " \t");
    else
        parsed_line = ft_strtrim(line + 3, " \t");
    if (ft_strncmp(line, "NO", 2) == 0 && ft_strschr(".xpm", line) != -1)
        map->path_texture[NORTH] = parsed_line;
    else if (ft_strncmp(line, "SO", 2) == 0 && ft_strschr(".xpm", line) != -1)
        map->path_texture[SOUTH] = parsed_line;
    else if (ft_strncmp(line, "WE", 2) == 0 && ft_strschr(".xpm", line) != -1)
        map->path_texture[WEST] = parsed_line;
    else if (ft_strncmp(line, "EA", 2) == 0 && ft_strschr(".xpm", line) != -1)
		map->path_texture[EAST] = parsed_line;
    else if (ft_strncmp(line, "F", 1) == 0)
        map->floor_hex = ft_char_to_rgb(parsed_line);
    else if (ft_strncmp(line, "C", 1) == 0)
        map->ceiling_hex = ft_char_to_rgb(parsed_line);
    if (ft_strchr(line, 'C') || ft_strchr(line, 'F'))
        free(parsed_line);
}

bool    is_valid_rgb(char **splited)
{
    int i;
    int j;

    i = -1;
    while (splited[++i])
    {
        j = -1;
        while (splited[i][++j])
            if (!ft_strchr("0123456789", splited[i][j]))
                return (false);
        if (j < 1 || j > 3)
            return (false);
    }
    if (i != 3)
        return (false);
    return (true);
}

bool	fill_map_config(t_map *map)
{
	int		params;
	char	*buffer;

	params = 0;
	buffer = NULL;
	while (map->string_map[map->str_index]
		&& map->string_map[map->str_index + 1] != '\0' && params < 6)
	{
		buffer = ft_substr(map->string_map, map->str_index,
				ft_strchr(map->string_map + map->str_index, '\n')
				- map->string_map - map->str_index);
		if (buffer == NULL)
			return (false);
		if (ft_strchr_array((char *[7]){"NO", "SO", "WE", "EA", "F", "C", NULL},
			buffer) != -1)
		{
			(ft_fill(buffer, map), params++);
			map->str_index += ft_strchr(map->string_map + map->str_index,
					'\n') - map->string_map - map->str_index;
		}
		else
			map->str_index++;
		free(buffer);
	}
	return (true);
}

bool    load_textures(t_data *data)
{
    t_img tmp;
    int     i;

    i = -1;
    while (++i < TEXTURE_COUNT)
    {
        tmp.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
                data->map.path_texture[i], &tmp.width, &tmp.height);
        if (!tmp.mlx_img)
            return (false);
        tmp.addr = (int *)mlx_get_data_addr(tmp.mlx_img,
                &tmp.bpp, &tmp.line_len, &tmp.endian);
        if (!tmp.addr)
            return (mlx_destroy_image(data->mlx_ptr, tmp.mlx_img), false);
        if (!create_texture_buffer_from_img(data, &tmp, i))
            return (mlx_destroy_image(data->mlx_ptr, tmp.mlx_img), false);
        mlx_destroy_image(data->mlx_ptr, tmp.mlx_img);
    }
    return (true);
}