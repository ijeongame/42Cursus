/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:54:01 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/12 16:35:39 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char		*dp;
	unsigned char		*sp;
	size_t				i;

	if (!dest && !src)
		return (0);
	sp = (unsigned char*)src;
	dp = (unsigned char*)dest;
	i = 0;
	while (i < size)
	{
		dp[i] = sp[i];
		if (sp[i] == (unsigned char)c)
			return (&dp[i] + 1);
		i++;
	}
	return (0);
}
