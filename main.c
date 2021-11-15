/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:43:56 by jforner           #+#    #+#             */
/*   Updated: 2021/11/15 19:49:15 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>
int	close(int keycode, t_vars *vars)
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel)/ 8);
	*(unsigned int *)dst = color;
}

int	mapcontrol(char *str)
{
	int		linelen;
	int		count;
	int		error;

	error = open(str, O_RDONLY);
	if (!ft_strstr(str, ".ber") || error == -1)
		return (0);
	ft_get_next_line();
	return (1);
}

int	main(int argc, char **argv)
{	
	// t_data	img;

	int		img_width;
	int		img_height;
	t_vars	vars;
	void	*xpm;
	char	*relative_path = "test.xpm";

	if (argc != 2)
		return (0);

	vars.mlx = mlx_init();
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Amogus");
	xpm = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	if (xpm == NULL)
		return (0);
	mlx_put_image_to_window(vars.mlx, vars.win, jpg, img_width, img_height);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 2, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
