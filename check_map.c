/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:37:16 by mcallejo          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:11 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (map[0][i])
		i++;
	vars->width = i;
	j = 1;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i != vars->width)
			return (0);
		j++;
	}
	vars->height = j;
	return (1);
}

int	check_is_closed(char **map, t_vars *vars)
{
	int		i;
	int		j;
	int		a;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[0][i] != '1' || map[vars->height - 1][i] != '1')
				return (0);
			i++;
		}
		j++;
		while (j < vars->height)
		{
			if (map[j][0] != '1' || map[j][vars->width - 1] != '1')
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_final_map(char **map, t_vars *vars)
{
	if (!is_rectangular(map, vars))
		return (0);
	if (!check_is_closed(map, vars))
		return (0);
	return (1);
}
