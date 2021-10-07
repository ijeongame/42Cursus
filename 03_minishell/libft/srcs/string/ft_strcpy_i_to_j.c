/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_i_to_j.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:22:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/06 22:22:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_i_to_j(char *line, int i, int j)
{
	char	*res;
	int		k;

	res = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	k = 0;
	while (i < j)
		res[k++] = line[i++];
	res[k] = '\0';
	return (res);
}
