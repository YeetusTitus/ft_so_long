/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:27:06 by jforner           #+#    #+#             */
/*   Updated: 2021/11/23 15:43:21 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	portal_activate(t_map *map)
{
	int	x;
	int	y;

	if (is_active(map))
	{
		y = -1;
		while (++y < map->height)
		{
			x = -1;
			while (++x < map->lenght)
			{
				if (map->map[y][x] == 'E')
				{
					mlx_put_image_to_window(map->mlx, map->win, map->img.grass,
						x * 64, y * 64);
					mlx_put_image_to_window(map->mlx, map->win,
						map->img.portalon, x * 64, y * 64);
				}
			}
		}
	}
}
