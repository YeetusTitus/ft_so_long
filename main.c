/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:56 by jforner           #+#    #+#             */
/*   Updated: 2021/11/25 16:15:19 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{	
	t_map	map;

	if (argc != 2 || !mapcontrol(argv[1], &map))
		return (ft_puterror(argc, &map, argv[1]));
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.lenght * 64,
			map.height * 64, "Amogus");
	file_to_img(&map);
	file_to_img2(&map);
	displaymap(&map);
	map.countstep = 0;
	mlx_key_hook(map.win, move_on_win, &map);
	mlx_hook(map.win, 17, 1L << 2, red_cross, &map);
	mlx_loop(map.mlx);
	return (0);
}
