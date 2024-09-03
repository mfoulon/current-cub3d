#include "cub3d.h"

int render_2d(t_data *data)
{
    draw_map(data);
    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
                                                    data->img->mlx_img, 0, 0);
    return (0);
}