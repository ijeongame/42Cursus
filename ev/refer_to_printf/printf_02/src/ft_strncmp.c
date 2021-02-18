/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:15 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || (!s1[i] || !s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
