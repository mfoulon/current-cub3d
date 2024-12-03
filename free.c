/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:08:01 by mafoulon          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:44 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_void_array(void **array, int n)
{
	int	i;

	i = -1;
	if (n == -1)
		while (array[++i])
			free(array[i]);
	else
		while (++i < n)
			if (array[i])
				free(array[i]);
	free(array);
}

void	free_array(char **array, int n)
{
	free_void_array((void **)array, n);
}

void	free_2d_array(void ***array, int n)
{
	int	i;

	i = -1;
	if (n == -1)
		while (array[++i])
			free_void_array(array[i], -1);
	else
		while (++i < n)
			if (array[i])
				free_void_array(array[i], -1);
}

void	free_mlx(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr != NULL)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	free_data(t_data *data)
{
	int	i;

	if (data->fd > 0)
		close(data->fd);
	if (data->map.map)
		free_array(data->map.map, -1);
	if (data->map.int_map)
		free_void_array((void **)data->map.int_map, data->map.height);
	if (data->map.string_map)
		free(data->map.string_map);
	i = -1;
	while (++i < TEXTURE_COUNT)
		if (data->map.path_texture[i])
			free(data->map.path_texture[i]);
	i = -1;
	while (++i < TEXTURE_COUNT)
		if (data->texture_buffer[i])
			free(data->texture_buffer[i]);
	free_mlx(data);
}
