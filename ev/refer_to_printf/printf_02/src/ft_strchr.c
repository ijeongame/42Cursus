/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:26:53 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strchr(char *s, int c)
{
	int		index;
	char	*target;

	index = 0;
	target = NULL;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			target = &s[index];
			break ;
		}
		index++;
	}
	if (s[index] == '\0' && s[index] == c)
		target = &s[index];
	return (target);
}
