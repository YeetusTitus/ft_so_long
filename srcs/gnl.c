/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforner <jforner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:24:43 by jforner           #+#    #+#             */
/*   Updated: 2021/11/17 17:33:10 by jforner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = (ft_strlenn(s1, 0) + ft_strlenn(s2, 0));
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[len] = 0;
	free(s1);
	return (str);
}

int	ft_chrcmp(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_bufset(char *buf, int fd)
{
	int	error;

	ft_memset(buf, 0, 1 + 1);
	error = read(fd, buf, 1);
	return (error);
}

int	ft_buftoline(char *buf, int fd, char **line)
{
	size_t		pos;
	int			error;

	pos = ft_strlenn(buf, 1) + ft_chrcmp(buf, '\n');
	*line = ft_strjoin(*line, buf);
	error = 1;
	if (!ft_chrcmp(*line, '\n'))
		error = ft_bufset(buf, fd);
	while (error && !ft_chrcmp(*line, '\n'))
	{
		if (error == -1 || !buf[0])
			return (0);
		*line = ft_strjoin(*line, buf);
		pos = ft_strlenn(*line, 1) + ft_chrcmp(buf, '\n');
		if (!ft_chrcmp(*line, '\n'))
			error = ft_bufset(buf, fd);
	}
	*line = ft_substr(*line, 0, pos);
	if (!*line || !*line[0])
		return (0);
	pos = ft_strlenn(buf, 1) + ft_chrcmp(buf, '\n');
	ft_memmove(buf, &buf[pos], 1);
	return (1);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[256][1 + 1];

	if (fd < 0 || fd > 255)
		return (0);
	line = malloc(1 * sizeof(char));
	line[0] = 0;
	if (!(ft_buftoline(buf[fd], fd, &line)))
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
