/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:27 by mjung             #+#    #+#             */
/*   Updated: 2021/01/11 01:37:57 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ldec_to_hex(unsigned long long target)
{
	unsigned long long	hex;
	char				*result;
	char				*to_hex;

	if (target == 0)
		return (ft_strdup("0"));
	hex = 16;
	to_hex = NULL;
	result = NULL;
	while (target)
	{
		to_hex = (char*)malloc(sizeof(char) * 2);
		if ((target % hex) == hex)
			to_hex[0] = '0';
		else if ((target % hex) < 10)
			to_hex[0] = (target % hex) + '0';
		else
			to_hex[0] = ((target % hex) - 10) + 'a';
		to_hex[1] = '\0';
		result = ft_strjoin(to_hex, result);
		target /= hex;
	}
	return (result);
}

void	pointer_precision(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;
	int		len_value;

	if (*(*format)->precision == 0 && ((*format)->value == NULL))
	{
		free(*result);
		free((*format)->value);
		*result = NULL;
		(*format)->value = NULL;
	}
	len_value = ft_strlen(*result);
	if (!(*format)->precision || (((*format)->precision - len_value) <= 0))
		return ;
	add_str = NULL;
	empty_width = *((*format)->precision) - len_value;
	while (empty_width-- > 0)
		add_str = ft_strjoin(add_str, ft_strdup("0"));
	*result = ft_strjoin(add_str, *result);
}

void	get_pointer_value(va_list ap, t_format **format, char **result)
{
	(*format)->value = va_arg(ap, void *);
	*result = ldec_to_hex((unsigned long long)(*format)->value);
	if ((*format)->precision)
		pointer_precision(format, result);
	*result = ft_strjoin(ft_strdup("0x"), *result);
	apply_format_width(format, result);
	(*format)->value = NULL;
}
