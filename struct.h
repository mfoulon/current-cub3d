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

# define WALL '1'
# define EMPT '0'
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
	char	*path;
	void	*mlx_img;
	int		*addr;
	int		bpp;	// bits per pixel
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

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

// typedef struct s_map
// {
// 	char			**map;
// 	char			*string_map;
// 	char			*path_texture[4];
// 	char			index;
// 	int						str_index;
// 	int						**int_map;
// 	int						height;
// 	int						width;
// 	int						offset;
// 	int						col;
// 	int						row;
// 	int						start_row;
// 	int						start_col;
// 	int						start_map;
// 	long					floor_hex;
// 	long					ceiling_hex;
// 	void					*no_img;
// 	void					*so_img;
// 	void					*we_img;
// 	void					*ea_img;
// 	t_direction				start_dir;
// 	//t_texture	*texture;
// }	t_map;

typedef struct s_map
{
	char					**map;
	char					*string_map;
	int						**int_map;
	int						str_index;
	int						width;
	int						height;
	void					*no_img;
	void					*so_img;
	void					*we_img;
	void					*ea_img;
	long					floor_hex;
	long					ceiling_hex;
	int						col;
	int						row;
	char					index;
	int						start_row;
	int						start_col;
	int						start_map;
	char					*path_texture[4];
	int						offset;
	t_direction	start_dir;
}	t_map;

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

typedef struct s_keys
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_data
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*texture_buffer[4];
	int		**pixels;
	t_ray	ray;
	t_player	player;
	t_map	map;
	t_keys	keys;
}	t_data;

// typedef struct s_texture
// {
// 	char	*east_wall;
// 	char	*west_wall;
// 	char	*north_wall;
// 	char	*south_wall;
// 	char	*floor;
// 	char	*ceiling;
// }	t_texture;

#endif