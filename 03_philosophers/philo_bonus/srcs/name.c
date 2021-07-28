/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:36:51 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/07/28 21:36:26 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// char	*make_sem_name(char *name, int n)
// {
// 	char	*result;
// 	int		num;
// 	int		i;

// 	i = 0;
// 	num = n;
// 	while (num)
// 	{
// 		num /= 10;
// 		++i;
// 	}
// 	result = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	num = -1;
// 	while (++num < i)
// 		result[num] = name[num];
// 	while (n)
// 	{
// 		result[i++] = n % 10 + '0';
// 		n /= 10;
// 	}
// 	result[i] = 0;
// 	return (result);
// }

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) + (len1 + len2 + 1))))
		return (0);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*make_sem_name(t_philo *philo)
{
	char	*name;

	name = ft_strdup("philo");
	return (ft_strjoin(name, ft_itoa(philo->n)));
}