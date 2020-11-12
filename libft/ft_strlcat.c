/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:55:08 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/12 13:33:12 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (d_len > size)
		d_len = size;
	if (d_len == size)
		return (size + s_len);
	if (s_len < size - d_len)
	{
		ft_memcpy(dest + d_len, src, s_len);
		dest[d_len + s_len] = '\0';
	}
	else
	{
		ft_memcpy(dest + d_len, src, size - d_len - 1);
		dest[size - 1] = '\0';
	}
	return (d_len + s_len);
}
