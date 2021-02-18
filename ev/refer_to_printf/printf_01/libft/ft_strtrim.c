/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:11:42 by inshin            #+#    #+#             */
/*   Updated: 2020/11/04 22:12:45 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		new_len;
	int		start;
	int		end;

	start = -1;
	while (s1[++start])
		if (!ft_strchr(set, s1[start]))
			break ;
	end = ft_strlen(s1);
	while (s1[--end] && end > 0)
		if (!ft_strchr(set, s1[end]))
			break ;
	if (start >= end)
		return (ft_strdup(""));
	new_len = end - start + 1;
	new_str = ft_substr(s1, start, new_len);
	return (new_str);
}
