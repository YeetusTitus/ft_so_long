/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:23:28 by jforner           #+#    #+#             */
/*   Updated: 2021/11/24 20:01:29 by jforner          ###   ########.fr       */
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
	ft_putstr_fd("Number of steps :\t", 1);
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

void	delete_screen(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.red);
	mlx_destroy_image(map->mlx, map->img.grass);
	mlx_destroy_image(map->mlx, map->img.bedrock);
	mlx_destroy_image(map->mlx, map->img.portaloff);
	mlx_destroy_image(map->mlx, map->img.portalon);
	mlx_destroy_image(map->mlx, map->img.pink);
	mlx_destroy_image(map->mlx, map->img.blue);
	mlx_destroy_image(map->mlx, map->img.maroon);
	mlx_destroy_image(map->mlx, map->img.grey);
	mlx_destroy_image(map->mlx, map->img.violet);
	mlx_destroy_image(map->mlx, map->img.lime);
	mlx_destroy_window(map->mlx, map->win);
}

void	mogus_corpse(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'b')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dblue, x * 64, y * 64);
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'm')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dmaroon, x * 64, y * 64);
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'v')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dviolet, x * 64, y * 64);
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'g')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dgrey, x * 64, y * 64);
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'l')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dlime, x * 64, y * 64);
	if (map->map[y][x] == '0' && map->mapc[y][x] == 'p')
		mlx_put_image_to_window(map->mlx, map->win,
			map->img.dpink, x * 64, y * 64);
}
