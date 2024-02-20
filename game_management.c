/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:22:48 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 19:03:11 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->y - 1][vars->x] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
		vars->y--;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->up,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->y + 1][vars->x] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
		vars->y++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->down,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->y][vars->x - 1] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
		vars->x--;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->left,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->y][vars->x + 1] != '1')
	{
		if (vars->map[vars->y][vars->x] == 'C')
		{
			vars->collect--;
			vars->map[vars->y][vars->x] = '0';
		}
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
		vars->x++;
		vars->moves++;
		ft_printf("Moves: %i\n", vars->moves);
		if (vars->map[vars->y][vars->x] == 'E' && vars->collect == 0)
			exit_win(vars);
		if (vars->map[vars->y][vars->x] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->right,
				vars->x * vars->pos_w, vars->y * vars->pos_h);
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
