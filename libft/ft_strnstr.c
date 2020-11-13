/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:55:57 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/12 17:39:24 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2020/11/12 13:27:02 by hkwon            ###   ########.fr       */
>>>>>>> 9334b2ea73bf5697d7421d5bd5d68622be107bcf
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char		*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < size)
	{
		j = 0;
		while (little[j] && big[i] == little[j] && i < size)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)&big[i - j]);
		i = i - j + 1;
=======
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
>>>>>>> 9334b2ea73bf5697d7421d5bd5d68622be107bcf
	}
	return (0);
}
