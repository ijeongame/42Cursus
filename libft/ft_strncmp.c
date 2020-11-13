/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:55:49 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/12 17:02:08 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2020/11/12 13:26:44 by hkwon            ###   ########.fr       */
>>>>>>> 9334b2ea73bf5697d7421d5bd5d68622be107bcf
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
<<<<<<< HEAD
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1++;
	str2 = (unsigned char *)s2++;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
=======
	unsigned char *str1;
	unsigned char *str2;

	while (n--)
	{
		str1 = (unsigned char *)s1++;
		str2 = (unsigned char *)s2++;
		if (str1 != str2)
			return (str1 - str2);
		if (str1 == '\0')
			return (0);
>>>>>>> 9334b2ea73bf5697d7421d5bd5d68622be107bcf
	}
	return (0);
}
