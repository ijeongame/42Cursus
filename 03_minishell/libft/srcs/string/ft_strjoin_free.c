/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:06:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/07 16:10:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int flag)
{
	int		len1;
	int		len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) + (len1 + len2 + 1));
	if (!res)
		return (0);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	if (flag == 1)
		free(s1);
	if (flag == 2)
		free(s2);
	if (flag == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}
