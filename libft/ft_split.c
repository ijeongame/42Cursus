/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:34:35 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/14 21:05:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cnt_size(char const *s, char c)
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

static int		cnt_word(char const *s, char c)
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

static char		**arr_free(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (0);
}

char			**ft_split(const char *s, char c)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1))))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			size = cnt_size(s, c);
			if (!(res[i] = malloc(size + 1)))
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
