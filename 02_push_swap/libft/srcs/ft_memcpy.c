/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:54:26 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/13 16:33:24 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}
