/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:37:16 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 17:20:38 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_rectangular(char **map, t_vars *vars)
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

int	check_is_closed(char *raw_map)
{
	int		i;

	i = 0;
	while (raw_map[i] != '\n')
	{
		if (raw_map[i] != '1')
			return (0);
		i++;
	}
	i++;
	while (raw_map[i])
	{
		if ((raw_map[i - 1] == '\n' && raw_map[i] != '1')
			|| (raw_map[i + 1] == '\n' && raw_map[i] != '1'))
			return (0);
		i++;
	}
	i--;
	while (raw_map[i] != '\n')
	{
		if (raw_map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	check_min_size(t_vars *vars)
{
	if (vars->height < 3 || vars->width < 3)
		return (0);
	if (vars->height > 40 || vars->width > 76)
		return (0);
	if (vars->height * vars->width < 15)
		return (0);
	return (1);
}

int	check_min_type_char(char *raw_map, t_vars *vars)
{
	int		i;

	i = 0;
	vars->collect = 0;
	while (raw_map[i])
	{
		if (raw_map[i] != 'P' && raw_map[i] != 'E' && raw_map[i] != 'C'
			&& raw_map[i] != '1' && raw_map[i] != '0' && raw_map[i] != '\n')
			return (0);
		i++;
	}
	if (num_strchr('P', raw_map) != 1 || num_strchr('E', raw_map) != 1)
		return (0);
	vars->collect = num_strchr('C', raw_map);
	if (vars->collect < 1)
		return (0);
	return (1);
}

int	check_final_map(char **map, t_vars *vars, char *raw_map)
{
	if (!check_is_rectangular(map, vars))
		return (0);
	if (!check_is_closed(raw_map))
		return (0);
	if (!check_min_size(vars))
		return (0);
	if (!check_min_type_char(raw_map, vars))
		return (0);
	return (1);
}
