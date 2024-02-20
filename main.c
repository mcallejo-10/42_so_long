/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:11:33 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 18:08:30 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (free(img), 1);
	if (!get_final_map(argc, argv, vars))
		return (0);
	init_game(vars, img);
	return (0);
}
