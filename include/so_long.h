/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:44:44 by jforner           #+#    #+#             */
/*   Updated: 2021/11/17 17:23:11 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map {
	int		lenght;
	int		height;
	char	**map;
	char	error;
}				t_map;

//map
int		mapcontrol(char *str, t_map	*map);
int		map_size(char *str, t_map *map);
int		maperror(t_map *map);
int		maperror2(int *test, t_map *map);

//display

//error

//events

//gnl
int		ft_bufset(char *buf, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_chrcmp(char *str, char c);
int		ft_buftoline(char *buf, int fd, char **line);
char	*get_next_line(int fd);

//utils
size_t	ft_strlenn(char *str, int t);
void	*ft_memset(void *str, char c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_fullstr(char *s, unsigned int start, size_t len, char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif