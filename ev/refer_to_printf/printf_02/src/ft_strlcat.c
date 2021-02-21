/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:07 by mjung             #+#    #+#             */
/*   Updated: 2021/01/09 23:46:42 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	int		srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (dst[index] != '\0')
		dst++;
	if (dstsize > 0)
	{
		while ((int)index < ((int)dstsize - (int)dstlen - 1)
		&& src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	if (dstsize < dstlen)
		return (srclen + dstsize);
	else
		return (dstlen + srclen);
}
