/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:06 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/05 17:15:21 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnrcmp(char *s1, const char *s2, int n)
{
	int				i;
	int				j1;
	int				j2;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	j1 = ft_strlen(s1);
	j2 = 4;
	while (j1 >= 0 && i < n)
	{
		if (str1[j1] != str2[j2])
			return (str1[j1] - str2[j2]);
		j1--;
		j2--;
		i++;
	}
	if (i < n)
		return (-1);
	return (0);
}

int	num_strchr(char c, char *str)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

int	map_strchr(char c, char **map)
{
	int		j;
	int		n;

	n = 0;
	j = 0;
	while (map[j])
	{
		n = n + num_strchr(c, map[j]);
		j++;
	}
	return (n);
}

void	p_position(t_vars *vars)
{
	vars->pos_h = 32;
	vars->pos_w = 32;
	while (vars->map[vars->y])
	{
		vars->x = 0;
		while (vars->map[vars->y][vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				break ;
			vars->x++;
		}
		if (vars->map[vars->y][vars->x] == 'P')
			break ;
		vars->y++;
	}
}
