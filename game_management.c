/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:22:48 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 17:21:53 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->y - 1][vars->x] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN!\n", 9);
		exit_me(vars);
	}
	if (vars->map[vars->y - 1][vars->x] != '1' \
		&& vars->map[vars->y - 1][vars->x] != 'E')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->grass_path,
			vars->x * vars->width, vars->y * vars->height);
		vars->y--;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->up_path,
			vars->x * vars->width, vars->y * vars->height);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->y + 1][vars->x] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN!\n", 9);
		exit_me(vars);
	}
	if (vars->map[vars->y + 1][vars->x] != '1' \
		&& vars->map[vars->y + 1][vars->x] != 'E')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->grass_path,
			vars->x * vars->width, vars->y * vars->height);
		vars->y++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->down_path,
			vars->x * vars->width, vars->y * vars->height);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->y][vars->x - 1] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN!\n", 9);
		exit_me(vars);
	}
	if (vars->map[vars->y][vars->x - 1] != '1' \
		&& vars->map[vars->y][vars->x - 1] != 'E')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->grass_path,
			vars->x * vars->width, vars->y * vars->height);
		vars->x--;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->left_path,
			vars->x * vars->width, vars->y * vars->height);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->y][vars->x + 1] == 'E' && vars->collect == 0)
	{
		write(1, "YOU WIN!\n", 9);
		exit_me(vars);
	}
	if (vars->map[vars->y][vars->x + 1] != '1' \
		&& vars->map[vars->y][vars->x + 1] != 'E')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->grass_path,
			vars->x * vars->width, vars->y * vars->height);
		vars->x++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->right_path,
			vars->x * vars->width, vars->y * vars->height);
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_me(vars);
	else if (keycode == 13 || keycode == 126)
		move_up(vars);
	else if (keycode == 1 || keycode == 125)
		move_down(vars);
	else if (keycode == 0 || keycode == 123)
		move_left(vars);
	else if (keycode == 2 || keycode == 124)
		move_right(vars);
	return (0);
}
