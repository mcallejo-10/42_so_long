/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:11:33 by mcallejo          #+#    #+#             */
/*   Updated: 2024/01/17 21:06:25 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;
	
	vars = malloc(sizeof(t_vars));
	get_final_map(argc, argv, vars);
	return (0);
}
