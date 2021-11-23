/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:23:28 by jforner           #+#    #+#             */
/*   Updated: 2021/11/23 15:01:48 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	pcoord(t_map *map, int co[])
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->lenght)
		{
			if (map->map[y][x] == 'P')
			{
				co[0] = x;
				co[1] = y;
			}
		}
	}
}

void	walkcount(t_map *map)
{
	ft_putstr_fd("Nombre de pas :\t", 1);
	map->countstep++;
	ft_putunbr(map->countstep);
	ft_putchar_fd('\n', 1);
}

int	is_active(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->lenght)
		{
			if (map->map[y][x] == 'C')
				return (0);
		}
	}
	return (1);
}
