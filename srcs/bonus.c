/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:27:06 by jforner           #+#    #+#             */
/*   Updated: 2021/11/24 21:19:34 by jforner          ###   ########.fr       */
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

void	mapcolor(t_map *map, int count, int y, int x)
{
	if (count % 6 == 0)
		map->mapc[y][x] = 'b';
	if (count % 6 == 1)
		map->mapc[y][x] = 'm';
	if (count % 6 == 2)
		map->mapc[y][x] = 'g';
	if (count % 6 == 3)
		map->mapc[y][x] = 'l';
	if (count % 6 == 4)
		map->mapc[y][x] = 'p';
	if (count % 6 == 5)
		map->mapc[y][x] = 'v';
}

void	color(t_map *map, int x, int y)
{
	static size_t	count = 0;

	if (count % 6 == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->img.blue,
			x * 64, y * 64);
	if (count % 6 == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.maroon,
			x * 64, y * 64);
	if (count % 6 == 2)
		mlx_put_image_to_window(map->mlx, map->win, map->img.grey,
			x * 64, y * 64);
	if (count % 6 == 3)
		mlx_put_image_to_window(map->mlx, map->win, map->img.lime,
			x * 64, y * 64);
	if (count % 6 == 4)
		mlx_put_image_to_window(map->mlx, map->win, map->img.pink,
			x * 64, y * 64);
	if (count % 6 == 5)
		mlx_put_image_to_window(map->mlx, map->win, map->img.violet,
			x * 64, y * 64);
	mapcolor(map, count, y, x);
	count++;
}

void	file_to_img2(t_map *map)
{
	int	imgw;
	int	imgh;

	map->img.dpink = mlx_xpm_file_to_image(map->mlx, "img/dp.xpm",
			&imgw, &imgh);
	map->img.dlime = mlx_xpm_file_to_image(map->mlx, "img/dl.xpm",
			&imgw, &imgh);
	map->img.dblue = mlx_xpm_file_to_image(map->mlx, "img/db.xpm",
			&imgw, &imgh);
	map->img.dgrey = mlx_xpm_file_to_image(map->mlx, "img/dg.xpm",
			&imgw, &imgh);
	map->img.dmaroon = mlx_xpm_file_to_image(map->mlx, "img/dm.xpm",
			&imgw, &imgh);
	map->img.dviolet = mlx_xpm_file_to_image(map->mlx, "img/dv.xpm",
			&imgw, &imgh);
}

void	dead_mogus(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->lenght)
		{
			mogus_corpse(map, x, y);
		}
	}
}
