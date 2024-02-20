/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:18:42 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 17:59:32 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	exit_win(t_vars *vars)
{
	write(1, "YOU WIN!\n", 9);
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	exit_me(t_vars *vars)
{
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	error_exit(t_vars *vars)
{
	write(1, "Error\n", 7);
	free_map(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
