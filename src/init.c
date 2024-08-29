#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("[init_map(...)] : t_map malloc failed");
	garbage_collector(map, false);
	map->height = 0;
	map->width = 0;
	map->texture = malloc(sizeof(t_texture));
	if (!map->texture)
		ft_error("[init_map(...)] : t_texture malloc failed");
	garbage_collector(map->texture, false);
	return (map);
}

t_mlx   *init_mlx(void)
{
    t_mlx   *mlx;

    mlx = malloc(sizeof(t_mlx));
    if (!mlx)
        ft_error("[init_mlx(...)] : t_mlx malloc failed");
    garbage_collector(mlx, false);
    return (mlx);
}

t_img   *init_img(void)
{
    t_img   *image;

    image = malloc(sizeof(t_img));
    if (!image)
        ft_error("[init_img(...)] : t_img malloc failed");
    garbage_collector(image, false);
    image->mlx_img = NULL;
    image->addr = NULL;
    image->bpp = 0;
    image->line_len = 0;
    image->endian = 0;
    return (image);
}

t_game  *init_game(void)
{
    t_game  *game;
    
    game = malloc(sizeof(t_game));
    if (!game)
        ft_error("[init_game(...)] : t_game malloc failed");
    garbage_collector(game, false);
    game->map = init_map();
	game->mlx = init_mlx();
	game->img = init_img();
	return (game);
}