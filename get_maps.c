/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:11:26 by mcallejo          #+#    #+#             */
/*   Updated: 2024/01/17 21:36:53 by mcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_raw_map(char *map_path)
{
	int		fd;
	char	*line;
	char	*raw_map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	raw_map = ft_strdup("");
	while (line)
	{
		raw_map = ft_strjoin(raw_map, line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	printf("Mapa leído:\n%s\n", raw_map);
	return (raw_map);
}

int	check_map_name(char *map_path)
{
	if (ft_strlen(map_path) < 5)
		return (0);
	if (ft_strnrcmp(map_path, ".ber", 4) != 0)
		return (0);
	return (1);
}

char	**get_map(int argc, char **argv, t_vars *vars)
{
	char	*raw_map;
	char	**map;

	if (argc != 2 || !check_map_name(argv[1]))
	{
		write(1, "Error1\n", 6);
	}
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
	{
		write(1, "Error2\n", 6);
		return (NULL);
	}
	map = ft_split(raw_map, '\n');
	if (!check_final_map(map, vars, raw_map))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (map);
}

int	check_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	if (check_exit(map, x + 1, y) == 1)
		return (1);
	if (check_exit(map, x - 1, y) == 1)
		return (1);
	if (check_exit(map, x, y + 1) == 1)
		return (1);
	if (check_exit(map, x, y - 1) == 1)
		return (1);
	return (1);
}

char	**get_final_map(int argc, char **argv, t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->map = get_map(argc, argv, vars);
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
	printf("x: %i\ny: %i\n", vars->x, vars->y);
	printf("HOLAAA\n");
	if (!check_exit(vars->map, vars->x, vars->y))
		return (write(1, "Error_ff\n", 9), NULL);
	free(vars->map);
	vars->map = get_map(argc, argv, vars);
	printf("ADDIOOOOSS\n");
	return (vars->map);
}
