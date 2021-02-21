/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:32:07 by inshin            #+#    #+#             */
/*   Updated: 2020/10/30 02:57:55 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_h;
	size_t	len_n;
	char	*og;
	char	*cmp;

	og = (char *)big;
	cmp = (char *)little;
	len_h = ft_strlen(og);
	len_n = ft_strlen(cmp);
	if (!*cmp)
		return ((char *)og);
	if (len_n > len || len_n > len_h)
		return (0);
	if (len > len_h)
		len = len_h;
	while (len-- >= len_n)
	{
		if (ft_strncmp(og, cmp, len_n) == 0)
			return ((char *)og);
		og++;
	}
	return (0);
}
