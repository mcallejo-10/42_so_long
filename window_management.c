/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:40:37 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 17:17:18 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_struct(t_vars *vars, t_img *img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->grass = mlx_xpm_file_to_image(vars->mlx, "textures/Grass.xpm",
			&img->img_width, &img->img_height);
	if (vars->grass == NULL)
		error_exit(vars);
	vars->tree = mlx_xpm_file_to_image(vars->mlx, "textures/tree_1.xpm",
			&img->img_width, &img->img_height);
	if (vars->tree == NULL)
		error_exit(vars);
	vars->house = mlx_xpm_file_to_image(vars->mlx, "textures/house_op.xpm",
			&img->img_width, &img->img_height);
	if (vars->house == NULL)
		error_exit(vars);
	vars->cat = mlx_xpm_file_to_image(vars->mlx, "textures/cat.xpm",
			&img->img_width, &img->img_height);
	if (vars->cat == NULL)
		error_exit(vars);
	put_image_struct_alan(vars, img);
}

void	put_image_struct_alan(t_vars *vars, t_img *img)
{
	vars->up = mlx_xpm_file_to_image(vars->mlx, "textures/alan_up.xpm",
			&img->img_width, &img->img_height);
	if (vars->up == NULL)
		error_exit(vars);
	vars->down = mlx_xpm_file_to_image(vars->mlx, "textures/alan_down.xpm",
			&img->img_width, &img->img_height);
	if (vars->down == NULL)
		error_exit(vars);
	vars->left = mlx_xpm_file_to_image(vars->mlx, "textures/alan_left.xpm",
			&img->img_width, &img->img_height);
	if (vars->left == NULL)
		error_exit(vars);
	vars->right = mlx_xpm_file_to_image(vars->mlx, "textures/al_right.xpm",
			&img->img_width, &img->img_height);
	if (vars->right == NULL)
		error_exit(vars);
}

void	background(t_vars *vars, t_img	*img)
{
	img->j = 0;
	while (vars->map[img->j])
	{
		img->i = 0;
		while (vars->map[img->j][img->i])
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->grass,
				img->i * img->img_width, img->j * img->img_height);
			img->i++;
		}
		img->j++;
	}
}

void	get_images(t_vars *vars, t_img *img)
{
	img->j = 0;
	while (vars->map[img->j])
	{
		img->i = 0;
		while (vars->map[img->j][img->i])
		{
			if (vars->map[img->j][img->i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tree,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->cat,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->down,
					img->i * img->img_width, img->j * img->img_height);
			if (vars->map[img->j][img->i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->house,
					img->i * img->img_width, img->j * img->img_height);
			img->i++;
		}
		img->j++;
	}
}

void	init_game(t_vars *vars, t_img *img)
{
	img->img_width = 32;
	img->img_height = 32;
	vars->x = 0;
	vars->y = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * img->img_width,
			vars->height * img->img_height, "so_far_so_long");
	put_image_struct(vars, img);
	background(vars, img);
	get_images(vars, img);
	p_position(vars);
	mlx_hook(vars->win, 02, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 17, 1L << 2, exit_me, vars);
	mlx_loop(vars->mlx);
}
