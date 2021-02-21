/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:01 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		total_size;
	int		idx_total;
	int		idx_tmp;

	if (!s1 && !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char*)malloc(sizeof(char) * (total_size + 1))))
		return (NULL);
	idx_total = 0;
	idx_tmp = 0;
	if (s1)
		while ((char)s1[idx_tmp] != '\0')
			result[idx_total++] = s1[idx_tmp++];
	idx_tmp = 0;
	if (s2)
		while ((char)s2[idx_tmp] != '\0')
			result[idx_total++] = s2[idx_tmp++];
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	result[idx_total] = '\0';
	return (result);
}
