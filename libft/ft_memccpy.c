/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:54:01 by hkwon             #+#    #+#             */
/*   Updated: 2020/10/17 03:54:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!dest && !src)
		return (0);
	dp = dest;
	sp = src;
	while (size--)
	{
		if ((*dp++ == *sp++) == (unsigned char)c)
			return (dp);
	}
	return (0);
}
