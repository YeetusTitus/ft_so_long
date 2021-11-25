/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:44:44 by jforner           #+#    #+#             */
/*   Updated: 2021/11/25 11:43:56 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_img {
	void	*grass;
	void	*red;
	void	*bedrock;
	void	*portaloff;
	void	*portalon;
	void	*pink;
	void	*maroon;
	void	*blue;
	void	*lime;
	void	*grey;
	void	*violet;
	void	*dpink;
	void	*dmaroon;
	void	*dblue;
	void	*dlime;
	void	*dgrey;
	void	*dviolet;
}				t_img;

typedef struct s_map {
	int				lenght;
	int				height;
	char			**map;
	char			**mapc;
	int				nbexit;
	int				nbcol;
	int				nbplay;
	char			error;
	int				fd;
	void			*mlx;
	void			*win;
	unsigned int	countstep;
	t_img			img;
}				t_map;

//map
int		mapcontrol(char *str, t_map	*map);
int		map_size(char *str, t_map *map);
int		map_check(char *str, t_map *map);
int		maperror(t_map *map);
int		maperror2(t_map *map);

//display
int		displaymap(t_map *map);
void	displayif(t_map *map, int y, int x);
void	file_to_img(t_map *map);
int		displaymap(t_map *map);
//error
int		ft_puterror(int argc, t_map *map, char *str);
int		fileverif(char *str);

//events
int		red_cross(int keycode, int x, int y, t_map *map);
int		move_on_win(int keycode, t_map *map);
void	change_play(t_map *map, int *co, int x2, int y2);
int		wclose(t_map *map);
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

//utils2
void	ft_strncpy(char *dest, char *src, int size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putunbr(unsigned int nb);

//utils3
void	walkcount(t_map *map);
void	pcoord(t_map *map, int co[]);
int		is_active(t_map *map);
void	delete_screen(t_map *map);
void	mogus_corpse(t_map *map, int x, int y);

//bonus
void	portal_activate(t_map *map);
void	mapcolor(t_map *map, int count, int y, int x);
void	color(t_map *map, int x, int y);
void	file_to_img2(t_map *map);
void	dead_mogus(t_map *map);

#endif