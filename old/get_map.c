/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:27:29 by codespace         #+#    #+#             */
/*   Updated: 2024/06/06 13:14:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_dim(t_map *map, char *path);

t_map	*get_map(char *path)
{
	int	fd;
	int	map_row;
	char	*line;
	t_map	*map;

	map = init_map();
	map->height++;
	get_map_dim(map, path);
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		ft_error("[get_map(...)] : map->map malloc failed");
	garbage_collector(map->map, false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map(...)] : opened file returned < 0");
	line = get_next_line(fd);
	map_row = 0;
	while (line)
	{
		if (*line != '\n')
		{
			if (is_texture_line(line))
				get_texture_line(map, line);
			else if (is_map_line(line))
				get_map_line(map, line, &map_row);
		}
		line = get_next_line(fd);
	}
	return (map);
}	

// check for closing fd
void	get_map_dim(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("[get_map_dim(...)] : opened file returned < 0");
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && is_map_line(line))
		{
			(map->height)++;
			if ((int)ft_strlen(line) > map->width)
				map->width = ft_strlen(line);
		}
		line = get_next_line(fd);
	}
}

bool	to_int_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->int_map = malloc(map->height * sizeof(int *));
	if (map->int_map == NULL)
		return (false);
	i = -1;
	while (++i < map->height)
	{
		map->int_map[i] = malloc((map->width + map->offset) * sizeof(int));
		if (map->int_map[i] == NULL)
			return (ft_free_void_array((void **)map->int_map, i),
				map->int_map = NULL, false);
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