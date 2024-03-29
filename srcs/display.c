/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:20:07 by jforner           #+#    #+#             */
/*   Updated: 2021/11/24 21:18:02 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	displayif(t_map *map, int y, int x)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img.bedrock,
			x * 64, y * 64);
	else
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img.grass,
			x * 64, y * 64);
		if (map->map[y][x] == 'E')
			mlx_put_image_to_window(map->mlx, map->win,
				map->img.portaloff, x * 64, y * 64);
		if (map->map[y][x] == 'C')
			color(map, x, y);
		if (map->map[y][x] == 'P')
			mlx_put_image_to_window(map->mlx, map->win, map->img.red,
				x * 64, y * 64);
	}
}

int	displaymap(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	map->mapc = (char **)malloc((sizeof(char *) * map->height) + 1);
	while (++y < map->height)
	{
		x = -1;
		map->mapc[y] = (char *)malloc((sizeof(char) * map->lenght) + 1);
		ft_strncpy(map->mapc[y], map->map[y], map->lenght);
		while (++x < map->lenght)
		{
			displayif(map, y, x);
		}
	}
	return (1);
}

void	file_to_img(t_map *map)
{
	int	imgw;
	int	imgh;

	map->img.red = mlx_xpm_file_to_image(map->mlx, "img/red.xpm",
			&imgw, &imgh);
	map->img.portaloff = mlx_xpm_file_to_image(map->mlx, "img/portaloff.xpm",
			&imgw, &imgh);
	map->img.portalon = mlx_xpm_file_to_image(map->mlx, "img/portal.xpm",
			&imgw, &imgh);
	map->img.grass = mlx_xpm_file_to_image(map->mlx, "img/grass.xpm",
			&imgw, &imgh);
	map->img.bedrock = mlx_xpm_file_to_image(map->mlx, "img/bedrock.xpm",
			&imgw, &imgh);
	map->img.pink = mlx_xpm_file_to_image(map->mlx, "img/p.xpm",
			&imgw, &imgh);
	map->img.lime = mlx_xpm_file_to_image(map->mlx, "img/l.xpm",
			&imgw, &imgh);
	map->img.blue = mlx_xpm_file_to_image(map->mlx, "img/b.xpm",
			&imgw, &imgh);
	map->img.grey = mlx_xpm_file_to_image(map->mlx, "img/g.xpm",
			&imgw, &imgh);
	map->img.maroon = mlx_xpm_file_to_image(map->mlx, "img/m.xpm",
			&imgw, &imgh);
	map->img.violet = mlx_xpm_file_to_image(map->mlx, "img/v.xpm",
			&imgw, &imgh);
}
