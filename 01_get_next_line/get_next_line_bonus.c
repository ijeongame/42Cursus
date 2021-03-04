/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:23:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/09 22:16:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_set_store(char **store, char *buf, int read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (*store != 0)
	{
		tmp = ft_strndup(*store, ft_strlen(*store));
		free(*store);
	}
	else
		tmp = ft_strndup("", 1);
	*store = ft_strjoin(tmp, buf);
	free(tmp);
	if (ft_strchr(*store, '\n'))
		return (1);
	return (0);
}

static int	get_store_line(char **store, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(*store, '\n'))
	{
		while ((*store)[i] && (*store)[i] != '\n')
			i++;
		*line = ft_strndup(*store, i);
		tmp = ft_strndup(*store + i + 1, ft_strlen(*store + i + 1));
		free(*store);
		*store = tmp;
		return (1);
	}
	else
	{
		*line = *store;
		*store = 0;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX + 1];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !(line))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (get_set_store(&store[fd], buf, read_size) || read_size == 0)
			break ;
	}
	if (read_size < 0)
		return (-1);
	return (get_store_line(&store[fd], line));
}
