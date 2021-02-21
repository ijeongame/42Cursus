/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:17 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substring;

	if (!s || !len || (unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(substring = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substring, &s[start], len + 1);
	return (substring);
}
