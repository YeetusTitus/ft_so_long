/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:20:15 by jforner           #+#    #+#             */
/*   Updated: 2021/12/06 18:34:57 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	red_cross(int keycode, int x, int y, t_map *map)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)map;
	exit(EXIT_SUCCESS);
}

int	wclose(t_map *map)
{
	int	y;

	delete_screen(map);
	y = -1;
	while (++y < map->height)
		free(map->map[y]);
	free(map->map);
	while (++y < map->height)
		free(map->mapc[y]);
	free(map->mapc);
	free(map->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	move_on_win(int keycode, t_map *map)
{
	int			co[2];

	pcoord(map, co);
	if (keycode == 53)
		wclose(map);
	if (keycode == 0)
		change_play(map, co, co[0] - 1, co[1]);
	if (keycode == 1)
		change_play(map, co, co[0], co[1] + 1);
	if (keycode == 2)
		change_play(map, co, co[0] + 1, co[1]);
	if (keycode == 13)
		change_play(map, co, co[0], co[1] - 1);
	portal_activate(map);
	dead_mogus(map);
	return (1);
}

void	change_play(t_map *map, int co[], int x2, int y2)
{
	if (is_active(map) && map->map[y2][x2] == 'E')
		wclose(map);
	if (map->map[y2][x2] != '1' )
	{
		if (map->map[y2][x2] != 'E')
		{
			mlx_put_image_to_window(map->mlx, map->win, map->img.grass,
				co[0] * 64, co[1] * 64);
			mlx_put_image_to_window(map->mlx, map->win, map->img.grass,
				x2 * 64, y2 * 64);
			mlx_put_image_to_window(map->mlx, map->win, map->img.red,
				x2 * 64, y2 * 64);
			map->map[co[1]][co[0]] = '0';
			map->map[y2][x2] = 'P';
			walkcount(map);
		}
	}
}
