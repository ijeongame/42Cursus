/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:34:15 by inshin            #+#    #+#             */
/*   Updated: 2020/11/13 09:01:58 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *cp_dst;
	unsigned char *cp_src;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		cp_dst = (unsigned char *)dst;
		cp_src = (unsigned char *)src;
		while (len--)
			*cp_dst++ = *cp_src++;
	}
	else
	{
		cp_dst = (unsigned char *)(dst + len - 1);
		cp_src = (unsigned char *)(src + len - 1);
		while (len--)
			*cp_dst-- = *cp_src--;
	}
	return (dst);
}
