/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:33:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/21 22:16:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		name_check(char *name)
{
	int len;

	len = ft_strlen(name);
	if (ft_strncmp(name + len - 4, ".cub", 4))
		return (0);
	return (1);
}

int		map_parse(t_cub *c, char *name)
{
	int				fd;
	char			*line;

	fd = open(name, O_RDONLY);
	if (!name_check(name) || fd < 0)
		return (err_msg("map name & file open error"));
	if (!map_check(c, fd, &line))
		return (err_msg("map check error"));
	while (line[0] != ' ' && !ft_isdigit(line[0]))
	{
		get_next_line(fd, &line);
		if (line[0] != ' ' && !ft_isdigit(line[0]))
			free(line);
	}
	map_render(c, fd, &line);
	if (!map_valid(c))
		return (0);
	if (line)
		free(line);
	close(fd);
	return (1);
}
