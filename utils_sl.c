/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:16:06 by mcallejo          #+#    #+#             */
/*   Updated: 2024/01/17 16:21:25 by mcallejo         ###   ########.fr       */
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
	printf("num de caractersPEC: %i\n%i\n", n, i);
	return (n);
}
