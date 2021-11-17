/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:00:23 by jforner           #+#    #+#             */
/*   Updated: 2021/11/17 17:28:07 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	maperror2(int *test, t_map *map)
{
	if (test[0] != 1)
		map->error = 'P';
	if (test[1] < 1)
		map->error = 'E';
	if (test[2] < 1)
		map->error = 'C';
	if (map->error != '0')
		return (0);
}

int	maperror(t_map *map)
{
	int		x;
	int		y;
	int		test[3];

	y = -1;
	while (++y < 3)
		test[y] = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->lenght)
		{
			if (map->map[0][x] != 1 || map->map[map->lenght - 1][x] != 1)
				map->error = '1';
			if (map->map[y][x] == 'P')
				test[0]++;
			if (map->map[y][x] == 'E')
				test[1]++;
			if (map->map[y][x] == 'C')
				test[2]++;
		}
	}
	return (maperror2(test, map));
}

int	map_size(char *str, t_map *map)
{
	int		error;
	char	*line;

	map = (t_map *)malloc(sizeof(t_map));
	map->error = '0';
	error = open(str, O_RDONLY);
	line = ft_get_next_line(error);
	if (!ft_strstr(str, ".ber") || error == -1 || !line)
		return (0);
	map->lenght = ft_strlenn(line, 1);
	map->height = 1;
	while (line)
	{
		line = ft_get_next_line(error);
		if (map->lenght != ft_strlenn(line, 1))
		{
			map->error = 'R';
			return (0);
		}
		map->height++;
	}
	close(str);
	free(line);
	return (1);
}

int	mapcontrol(char *str, t_map	*map)
{
	int		count;
	int		y;
	int		fd;

	if (!map_size(str, map))
		return (0);
	y = -1;
	fd = open(str, O_RDONLY);
	map->map = (char **)malloc(map->height * sizeof(char *) + 1);
	while (++y < map->height)
	{
		map->map[y] = ft_strndup(ft_get_next_line(fd), map->lenght);
		if (map->map[y][0] != 1 || map->map[y][map->lenght - 1] != 1)
		{
			map->error = '1';
			return (0);
		}
	}
	close(str);
	return (maperror(map));
}
