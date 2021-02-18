/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:10 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	int		srclen;

	index = 0;
	if (!src)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize > 0)
	{
		while (index < (dstsize - 1) && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (srclen);
}
