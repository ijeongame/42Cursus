/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:55:57 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/12 13:27:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (*s2 == '\0')
		return (char *)s1;
	len = ft_strlen(s2);
	while (*s1 && n >= len)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len) == 0)
			return (char *)s1;
		s1++;
		n--;
	}
	return (0);
}
