/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:00:23 by jforner           #+#    #+#             */
/*   Updated: 2021/11/25 16:50:48 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	maperror2(t_map *map)
{
	if (map->nbplay != 1)
		map->error = 'P';
	if (map->nbexit < 1)
		map->error = 'E';
	if (map->nbcol < 1)
		map->error = 'C';
	if (map->error != '0')
		return (0);
	return (1);
}

int	maperror(t_map *map)
{
	int		x;
	int		y;

	map->error = '0';
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->lenght)
		{
			if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
				map->error = '1';
			if (map->map[y][x] == 'P')
				map->nbplay++;
			if (map->map[y][x] == 'E')
				map->nbexit++;
			if (map->map[y][x] == 'C')
				map->nbcol++;
			if (map->map[y][x] != 'C' && map->map[y][x] != 'E' &&
				map->map[y][x] != '1' && map->map[y][x] != 'P' &&
				map->map[y][x] != '0')
				map->error = 'O';
		}
	}
	return (maperror2(map));
}

int	map_size(char *str, t_map *map)
{
	map->lenght = ft_strlenn(str, 1);
	map->height = 0;
	while (str[0])
	{
		if (str[0])
			free(str);
		if (map->lenght != (int)ft_strlenn(str, 1))
		{
			close (map->fd);
			map->error = 'R';
			return (0);
		}
		map->height++;
		str = ft_substr(get_next_line(map->fd), 0, map->lenght);
	}
	free(str);
	return (1);
}

int	map_check(char *str, t_map *map)
{
	char	*line;

	map->error = '0';
	map->fd = open(str, O_RDWR);
	if (map->fd < 0 || !fileverif(str))
		return (0);
	line = get_next_line(map->fd);
	if (line == NULL)
	{
		map->error = 'F';
		return (0);
	}
	if (!map_size(line, map))
		return (0);
	close(map->fd);
	return (map->lenght);
}

int	mapcontrol(char *str, t_map	*map)
{
	int		y;

	if (!map_check(str, map))
		return (0);
	map->nbcol = 0;
	map->nbexit = 0;
	map->nbplay = 0;
	y = -1;
	map->fd = open(str, O_RDONLY);
	map->map = (char **)malloc(map->height * sizeof(char *) + 1);
	while (++y < map->height)
	{
		map->map[y] = ft_substr(get_next_line(map->fd), 0, map->lenght);
		if (map->map[y][0] != '1' || map->map[y][map->lenght - 1] != '1')
		{
			map->error = '1';
			return (0);
		}
	}
	close(map->fd);
	return (maperror(map));
}
