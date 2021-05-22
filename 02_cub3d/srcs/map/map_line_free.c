/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 00:43:03 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/22 15:32:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_line_free(char **line, int check)
{
	if (check == 1)
	{
		if (*line)
			free(*line);
		return (err_msg("check news error"));
	}
	if (check == 2)
	{
		if (*line)
			free(*line);
		return (err_msg("check sfc error"));
	}
	if (check == 3)
	{
		if (*line)
			free(*line);
		return (err_msg("check resolution error"));
	}
	return (1);
}
