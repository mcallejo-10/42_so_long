/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcallejo <mcallejo@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:11:26 by mcallejo          #+#    #+#             */
/*   Updated: 2024/02/01 17:26:23 by mcallejo         ###   ########.fr       */
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
	raw_map = malloc(sizeof(char *) * 1);
	raw_map[0] = '\0';
	while (line)
	{
		raw_map = gnl_strjoin(raw_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
		write(1, "Error\nInvalid file\n", 20);
		exit (1);
	}
	raw_map = get_raw_map(argv[1]);
	if (!raw_map)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	map = ft_split(raw_map, '\n');
	if (!check_final_map(map, vars, raw_map))
	{
		write(1, "Error\nInvalid map\n", 19);
		free(raw_map);
		exit (1);
	}
	free(raw_map);
	return (map);
}

void	fill_map(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || x > vars->width || y < 0 || y > vars->height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill_map(map, x - 1, y, vars);
	fill_map(map, x + 1, y, vars);
	fill_map(map, x, y - 1, vars);
	fill_map(map, x, y + 1, vars);
}

char	**get_final_map(int argc, char **argv, t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->moves = 0;
	vars->map = get_map(argc, argv, vars);
	p_position(vars);
	fill_map(vars->map, vars->x, vars->y, vars);
	if (map_strchr('E', vars->map) > 0 || map_strchr('C', vars->map) > 0)
	{
		write(1, "Error\nIvalid exit\n", 19);
		free_map(vars->map);
		return (NULL);
	}
	free_map(vars->map);
	vars->map = get_map(argc, argv, vars);
	return (vars->map);
}
