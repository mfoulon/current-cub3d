/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:08:17 by mafoulon          #+#    #+#             */
/*   Updated: 2024/12/03 16:29:26 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_close(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

void	move_player(t_data *data)
{
	if (data->keys.forward)
		move_forward(data);
	if (data->keys.backward)
		move_backward(data);
	if (data->keys.right)
		move_right(data);
	if (data->keys.left)
		move_left(data);
}

int	on_keypress(int symbol, t_data *data)
{
	data->player.is_moving = true;
	if (symbol == XK_Escape)
		on_close(data);
	else if (symbol == XK_w)
		data->keys.forward = true;
	else if (symbol == XK_s)
		data->keys.backward = true;
	else if (symbol == XK_a)
		data->keys.left = true;
	else if (symbol == XK_d)
		data->keys.right = true;
	return (0);
}

int	on_keyrelease(int symbol, t_data *data)
{
	data->player.is_moving = false;
	if (symbol == XK_Escape)
		on_close(data);
	else if (symbol == XK_w)
		data->keys.forward = false;
	else if (symbol == XK_s)
		data->keys.backward = false;
	else if (symbol == XK_a)
		data->keys.left = false;
	else if (symbol == XK_d)
		data->keys.right = false;
	return (0);
}
