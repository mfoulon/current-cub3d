#include "cub3d.h"

void    ft_render(t_data *data)
{
    t_ray   ray;

    if (!create_map(data))
        return ;
    cast_ray(data, &ray);
    draw_map(data);
    free_void_array((void **)data->pixels, WIN_HEIGHT);
}

int     on_loop(t_data *data)
{
    if (data->win_ptr == NULL)
        return (0);
    move_player(data);
    ft_render(data);
    return (0);
}

void    init_window(t_data *data)
{
    data->win_ptr = mlx_new_window(
            data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    if (!data->win_ptr)
        return (free_mlx(data), ft_error(EX11));
    ft_render(data);
    mlx_hook(
            data->win_ptr, DestroyNotify, StructureNotifyMask, on_close, data);
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
    mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_keyrelease, data);
    mlx_loop_hook(data->mlx_ptr, on_loop, data);
    mlx_loop(data->mlx_ptr);
}