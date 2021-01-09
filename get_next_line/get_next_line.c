/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:24:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/09 20:03:22 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

static int	get_set_store(char **store, char *buf, int read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (*store != 0)
	{
		tmp = ft_strdup(*store);	
		free(*store);
	}
	else
		tmp = ft_strdup("");
	*store = ft_strjoin(tmp, buf);
	free(tmp);
	if (ft_strchr(*store, '\n'))
		return (1);
	return (0);
}

static int get_store_line(char **store, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(*store, '\n'))
	{
		while ((*store)[i] && (*store)[i] != '\n')
			i++;
		*line = ft_strndup(*store, i);
		tmp = ft_strdup(*store + i +1);
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
	static char	*store[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !(line))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (get_set_store(&store[fd], buf, read_size) || read_size == 0)
			break;
	}
	if (read_size < 0)
		return (-1);
	return (get_store_line(&store[fd], line));
}
