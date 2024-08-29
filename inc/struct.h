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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
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
	int			height;
	int			width;
	t_texture	*texture;
}	t_map;

typedef struct s_game
{
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;
}	t_game;



#endif