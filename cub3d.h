/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:07:34 by mafoulon          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:37 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

/************* libs ******************/
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "struct.h"
# include "../libft/libft.h"

/*********** minilibx ***************/
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/************* DEFINES ******************/

# define EMAP "Invalid map"
# define EARG "Invalid arguments"
# define EIO "I/O error"
# define EUNKN "Unknown error"
# define ENOENT "No such file or directory"
# define EX11 "X11 error"
# define ETXTUR "Texture error"
# define EFILE "File error"
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define MAX_FPS_AVG 10000

/**                 FUNCTIONS                   **/

/************* error.c *************/
void    ft_error(char *msg);
void	*garbage_collector(void *ptr, bool clean);

/********** free.c **************/
void	free_void_array(void **array, int n);
void	free_array(char **array, int n);
void    free_2d_array(void ***array, int n);
void    free_mlx(t_data *data);
void    free_data(t_data *data);

/********** hooks.c **************/
int	on_close(t_data *data);
void    move_player(t_data *data);
int on_keypress(int symbol, t_data *data);
int on_keyrelease(int symbol, t_data *data);

/********** init_map.c ********/
bool    resize_map(t_map *map, bool with_err);
bool    define_offset_and_width(t_map *map, char **parsed_line);
bool    init_map(t_map *map);

/********** move.c **************/
double  ft_min(double a, double b);
void    move_forward(t_data *data);
void    move_backward(t_data *data);
void    move_right(t_data *data);
void    move_left(t_data *data);

/********** parse_utils.c **************/
char    **split_join_sep(const char *s, char sep);
bool    check_map(t_map *map, char **parsed_line);
int ft_read(char **line, int fd);

/********** parse.c ********/
bool    fill_and_parse_data(char *av[], t_data *data);

/********** player.c ********/
void    init_player(t_player *player, t_data *data);

/********** ray.c **************/
void	cast_ray(t_data *data, t_ray *ray);

/********** render.c **************/
bool	create_texture_buffer_from_img(t_data *data,
		t_img *img, t_direction dir);
bool    create_map(t_data *data);
void	update_map(t_data *data, t_ray *ray, int x);
void    draw_map(t_data *data);

/********** solver.c ********/
bool	resolve_map(t_data *data, char **copy_map);

/********** textures_utils.c ********/
int	ft_strschr(char *s1, char *s2);
int	ft_strchr_array(char **sep, char *str);

/********** textures.c **************/
bool    is_valid_rgb(char **splited);
bool	fill_map_config(t_map *map);
bool    load_textures(t_data *data);

/********** window.c **************/
void    ft_render(t_data *data);
int     on_loop(t_data *data);
void    init_window(t_data *data);

#endif
