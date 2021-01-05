/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:24:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/05 20:50:20 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_store(char **store, char *buf, int read_size)
{
	char *tmp;

	buf[read_size] = '\0';
	if (*store != 0)
	{
		tmp = ft_strjoin(*store, buf);	
		free(*store);
	}
	else
		tmp = ft_strdup("");
	if (!(*store = ft_strjoin(tmp, buf)))
		return (-1);
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
		get_store(&store[fd], buf, read_size);
		if (ft_strchr(*store, '\n') || read_size == 0)
			break;
		// buf[read_size] = '\0';
		// if (store[fd] != 0)
		// {
		// 	tmp = ft_strjoin(store[fd], buf);
		// 	free(store[fd]);
		// }
		// else
		// 	tmp = ft_strdup("");
		// if (!(store[fd] = ft_strjoin(tmp, buf)))
		// 	return (-1);
		// if (ft_strchr(store[fd], '\n') || read_size == 0)
		// 	break;
	}
	if (read_size < 0)
		return (-1);
	return (read_size);
}
