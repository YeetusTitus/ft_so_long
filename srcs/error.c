/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:56:13 by jforner           #+#    #+#             */
/*   Updated: 2021/11/22 20:22:14 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	ft_puterror(int argc, t_map *map, char *str)
{
	ft_putstr_fd("Error\n", 1);
	if (argc != 2)
		ft_putstr_fd("Put the path of one map on the argument !\n", 1);
	else if (map->error != '0')
	{
		if (map->error == 'R')
			ft_putstr_fd("The map is not rectangular !\n", 1);
		if (map->error == '1')
			ft_putstr_fd("The map is not close !\n", 1);
		if (map->error == 'P')
			ft_putstr_fd("The number of player is not correct !\n", 1);
		if (map->error == 'C')
			ft_putstr_fd("There is no collectible !\n", 1);
		if (map->error == 'E')
			ft_putstr_fd("There is no exit !\n", 1);
		if (map->error == 'O')
			ft_putstr_fd("Wrong character in a map\n", 1);
		if (map->error == 'F')
			ft_putstr_fd("No character in the file\n", 1);
	}
	else if (!fileverif(str))
		ft_putstr_fd("It's not a .ber file\n", 1);
	else
		ft_putstr_fd(strerror(errno), 1);
	return (0);
}
