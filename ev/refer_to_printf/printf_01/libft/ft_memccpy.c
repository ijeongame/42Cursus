/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 02:43:10 by inshin            #+#    #+#             */
/*   Updated: 2020/11/13 09:10:40 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cp_dst;
	unsigned char	*cp_src;

	i = 0;
	cp_dst = (unsigned char *)dst;
	cp_src = (unsigned char *)src;
	while (i < n)
	{
		cp_dst[i] = cp_src[i];
		if (cp_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
