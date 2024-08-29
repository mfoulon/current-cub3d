/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:18:47 by baptistevie       #+#    #+#             */
/*   Updated: 2024/06/16 17:38:31 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_no_event(void *data)
{
    /* This function needs to exist, but it is useless for the moment */
	(void) data;
    return (0);
}

int	handle_input(int keysym, t_mlx *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

int	handle_keypress(int keysym, t_mlx *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);

    ft_printf("Keypress: %d\n", keysym);
    return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void) data;
    ft_printf("Keyrelease: %d\n", keysym);
    return (0);
}
