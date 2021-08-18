/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:50:52 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/08/17 19:55:38 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

static int	cnt_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static int	cnt_word(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

static char	**arr_free(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			size = cnt_size(s, c);
			res[i] = malloc(size + 1);
			if (!res[i])
				return (arr_free(res, i));
			ft_strlcpy(res[i++], s, size + 1);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}
