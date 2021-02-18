/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmyungjin <jungmyungjin@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:16:54 by jungmyungjin      #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		length;
	int		index;

	index = 0;
	length = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	while (index < length)
	{
		new[index] = ((char*)s1)[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
