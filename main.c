/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:56 by jforner           #+#    #+#             */
/*   Updated: 2021/11/17 17:32:48 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>

int	wclose(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	static int	i = 1;
	//123 to  126 is arrow key
	if (keycode >= 123 && keycode <= 126)
		printf("You walked %d steps !\n", i);
	i++;
	return (1);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data-> bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{	
	// t_data	img;
	// t_map	map;
	int		img_width;
	int		img_height;
	t_vars	vars;
	void	*xpm;
	// char	*relative_path = "test.xpm";

	// if (argc != 2 || !mapcontrol(argv[1], &map))
	// 	return (ft_puterror(argc ,&map));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,  64,  64, "Amogus");
	xpm = mlx_xpm_file_to_image(vars.mlx, "test2.xpm", &img_width, &img_height);
	if (xpm == NULL)
		return (0);
	mlx_put_image_to_window(vars.mlx, vars.win, xpm, 0, 0);
	xpm = mlx_xpm_file_to_image(vars.mlx, "test.xpm", &img_width, &img_height);
	if (xpm == NULL)
		return (0);
	mlx_put_image_to_window(vars.mlx, vars.win, xpm, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 2, wclose, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
