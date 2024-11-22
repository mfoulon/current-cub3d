/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:25:48 by codespace         #+#    #+#             */
/*   Updated: 2024/06/06 13:18:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture_line(char *line)
{
	return (ft_strnstr(line, "NO", 2) || ft_strnstr(line, "SO", 2)
			|| ft_strnstr(line, "EA", 2) || ft_strnstr(line, "WE", 2)
			|| ft_strnstr(line, "F", 1) || ft_strnstr(line, "C", 1));
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != ' '
			&& line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void	get_texture_line(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO", 2))
		map->texture->north_wall = line + 3;
	if (ft_strnstr(line, "SO", 2))
		map->texture->south_wall = line + 3;
	if (ft_strnstr(line, "EA", 2))
		map->texture->east_wall = line + 3;
	if (ft_strnstr(line, "WE", 2))
		map->texture->west_wall = line + 3;
	if (ft_strnstr(line, "C", 1))
		map->texture->ceiling = line + 2;
	if (ft_strnstr(line, "F", 1))
		map->texture->floor = line + 2;
}

void	get_map_line(t_map *map, char *line, int *row)
{
	int	i;

	map->map[*row] = malloc((map->width + 1) * sizeof(char));
	if (!map->map[*row])
		ft_error("[get_map_line(...)] : malloc failed");
	garbage_collector(map->map[*row], false);
	i = 0;
	while (i < map->width) // i or i+1 to handle the '\n' ? do we handle when lines are smallest than map->width?
	{
		map->map[*row][i] = line[i];
		i++; 
	}
	map->map[*row][i] = '\0';
	(*row)++;
}