/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:20:15 by jforner           #+#    #+#             */
/*   Updated: 2021/11/23 15:46:56 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	wclose(t_map *map)
{
	free(map->map);
	mlx_destroy_window(map->mlx, map->win);
	exit(1);
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
			portal_activate(map);
			walkcount(map);
		}
	}
}
