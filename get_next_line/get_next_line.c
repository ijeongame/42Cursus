/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:24:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/04 20:44:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !(line))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		
	}
	if (read_size < 0)
		return (-1);
	return (read_size);
}