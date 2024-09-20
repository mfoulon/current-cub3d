/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:56 by codespace         #+#    #+#             */
/*   Updated: 2024/06/16 17:35:07 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

/************* lib ******************/
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*********** minilibx ***************/
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/************* inc ******************/
# include "struct.h"
# include "define.h"


/**                 FUNCTIONS                   **/

/********** display.c **************/

/************* error.c *************/
void    ft_error(char *msg);
void	*garbage_collector(void *ptr, bool clean);
void	free_void_array(void **array, int n);

/********** get_map_utils.c ********/
bool	is_texture_line(char *line);
bool	is_map_line(char *line);
void	get_texture_line(t_map *map, char *line);
void	get_map_line(t_map *map, char *line, int *row);

/********** get_map.c **************/
t_map	*get_map(char *path);
t_map	*init_map(void);
void	get_map_dim(t_map *map, char *path);

/********** hooks.c **************/
int	on_close(t_data *data);
void    move_player(t_data *data);
int on_keypress(int symbol, t_data *data);
int on_keyrelease(int symbol, t_data *data);

/********** img.c **************/

/********** init.c **************/
t_map	*init_map(void);
t_mlx   *init_mlx(void);
t_img   *init_img(void);
t_data  *init_game(void);

/********** move.c **************/
double  ft_min(double a, double b);
void    move_forward(t_data *data);
void    move_backward(t_data *data);
void    move_right(t_data *data);
void    move_left(t_data *data);

/********** ray.c **************/
void	cast_ray(t_data *data, t_ray *ray);

/********** render.c **************/
bool	create_texture_buffer_from_img(t_data *data,
		t_img *img, t_direction dir);
bool    create_pixel_map(t_data *data);
void	update_pixel_map(t_data *data, t_ray *ray, int x);

#endif