/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:18:49 by inshin            #+#    #+#             */
/*   Updated: 2020/10/16 00:13:12 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cp_dst;
	unsigned char	*cp_src;

	i = 0;
	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i++ < n)
		*cp_dst++ = *cp_src++;
	return (dst);
}
