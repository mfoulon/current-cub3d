/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:47 by codespace         #+#    #+#             */
/*   Updated: 2024/06/16 17:24:22 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIN_WIDTH 640
# define WIN_HEIGHT 360

# define TEXTURE_SIZE 64
# define TEXTURE_COUNT 4

typedef enum e_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_direction;

typedef struct s_img
{
	void	*mlx_img;
	char	*path;
	int		*addr;
	int		bpp;	// bits per pixel
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_texture
{
	char	*east_wall;
	char	*west_wall;
	char	*north_wall;
	char	*south_wall;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_map
{
	char		**map;
	int			**int_map;
	int			height;
	int			width;
	int			offset;
	t_texture	*texture;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	px;
	double	py;
	double	movespeed;
	double	rotspeed;
	bool	is_moving;
}	t_player;

/**
 * All the raycasting data
 * 
 * cx The camera plane
 * dx The direction x
 * dy The direction y
 * mx The map x
 * my The map y
 * sx The step x
 * sy The step y
 * sdx The side distance x
 * sdy The side distance y
 * ddx The delta distance x
 * ddy The delta distance y
 * wd The wall distance
 * side The side of the wall hit
 * h The height of the wall
 * ds The draw start
 * de The draw end
 * wx The wall x
 */

typedef struct s_ray
{
	double	cx;
	double	dx;
	double	dy;
	int		mx;
	int		my;
	int		sx;
	int		sy;
	double	sdx;
	double	sdy;
	double	ddx;
	double	ddy;
	double	wd;
	int		side;
	int		h;
	int		ds;
	int		de;
	double	wx;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	px;
	double	py;
	double	movespeed;
	double	rotspeed;
	bool	is_moving;
}	t_player;

typedef struct s_keys
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_data
{
	t_mlx	*mlx;
	t_map	map;
	t_img	*img;
	t_ray	ray;
	t_player	*player;
	t_keys	keys;
	int		**pixels;
	int					*texture_buffer[4];
}	t_data;

#endif