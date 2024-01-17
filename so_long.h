/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:50:41 by mcallejo          #+#    #+#             */
/*   Updated: 2024/01/17 20:55:53 by mcallejo         ###   ########.fr       */
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
}	t_vars;
// SO LONG //

// GET_MAPS //
char	**get_final_map(int argc, char **argv, t_vars *vars);
char	**get_map(int argc, char **argv, t_vars *vars);
int		check_map_name(char *map_path);
char	*get_raw_map(char *map_path);
int		check_exit(char **map, int x, int y);

// CHECK_MAP //
int		check_final_map(char **map, t_vars *vars, char *raw_map);
int		check_is_closed(char **map, t_vars *vars);
int		check_is_rectangular(char **map, t_vars *vars);
int		check_min_size(t_vars *vars);
int		check_min_type_char(char *raw_map);

// UTILS SL //
int		ft_strnrcmp(char *s1, const char *s2, int n);
int		num_strchr(char c, char *str);

#endif