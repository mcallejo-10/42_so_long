/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:50:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 17:20:46 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		x;
	int		y;
	int		collect;
	int		moves;
	void	*right_path;
	void	*left_path;
	void	*down_path;
	void	*up_path;
	void	*house_path;
	void	*grass_path;
	void	*tree_path;
	void	*cat_path;
	void	*img;
}	t_vars;

typedef struct s_img
{
	int		img_width;
	int		img_height;
	int		i;
	int		j;
}	t_img;

// SO LONG //

// GET_MAPS //
char	**get_final_map(int argc, char **argv, t_vars *vars);
char	**get_map(int argc, char **argv, t_vars *vars);
int		check_map_name(char *map_path);
char	*get_raw_map(char *map_path);
void	fill_map(char **map, int x, int y, t_vars *vars);

// CHECK_MAP //
int		check_final_map(char **map, t_vars *vars, char *raw_map);
int		check_is_closed(char **map, t_vars *vars);
int		check_is_rectangular(char **map, t_vars *vars);
int		check_min_size(t_vars *vars);
int		check_min_type_char(char *raw_map, t_vars *vars);

// WINDOW MANAGEMENT //
void	put_image_struct(t_vars *vars, t_img *img);
// void	change_image(t_vars *vars, t_img *img, char *path);
void	background(t_vars *vars, t_img	*img);
void	get_images(t_vars *vars, t_img	*img);
void	init_game(t_vars *vars, t_img *img);

// GAME_MANAGEMENT //
int		key_press(int keycode, t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);

// UTILS SL //
int		ft_strnrcmp(char *s1, const char *s2, int n);
int		num_strchr(char c, char *str);
int		map_strchr(char c, char **map);
void	p_position(t_vars *vars);

// EXIT_FREE //
char	*free_map(char **map);
int		exit_me(t_vars *vars);
#endif