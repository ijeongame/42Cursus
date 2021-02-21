/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:01:25 by inshin            #+#    #+#             */
/*   Updated: 2020/11/23 03:24:58 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_tab_len(char const *s, char c)
{
	int		i;
	int		tab_len;

	if (!*s)
		return (0);
	i = 0;
	tab_len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			tab_len++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		tab_len++;
	return (tab_len);
}

static void		ft_free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static char		**ft_split_unit(char **tab, char const *s, char c, int tab_len)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && j < tab_len)
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			len++;
		}
		tab[j] = ft_substr(s, i - len, len);
		if (tab[j++] == NULL)
		{
			ft_free_tab(tab);
			return (tab);
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_len;

	tab_len = ft_get_tab_len(s, c);
	if (s == NULL || !(tab = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	tab = ft_split_unit(tab, s, c, tab_len);
	return (tab);
}
