/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uint_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:33 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:38:19 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	hex_precision(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;
	int		len_value;

	if (*(*format)->precision == 0 && *(int*)(*format)->value == 0)
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

char	*dec_to_hex(unsigned int target)
{
	unsigned int	hex;
	char			*result;
	char			*to_hex;

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

void	upper_string(char **s)
{
	int subtrack;
	int idx;

	if (*s == NULL)
		return ;
	idx = 0;
	subtrack = 'a' - 'A';
	while ((*s)[idx])
	{
		if ('a' <= (*s)[idx] && (*s)[idx] <= 'z')
		{
			(*s)[idx] = (*s)[idx] - subtrack;
		}
		idx++;
	}
}

void	get_uint_value(va_list ap, t_format **format, char **result)
{
	(*format)->value = (unsigned int*)malloc(sizeof(unsigned int));
	*((unsigned int*)(*format)->value) = va_arg(ap, unsigned int);
	(*format)->value_is_neg = (int*)malloc(sizeof(int));
	if ((*format)->type == 'u')
		*result = apply_sign(format, ft_itoa(*(unsigned int*)(*format)->value));
	else
		*result =
		apply_sign(format, dec_to_hex(*(unsigned int*)(*format)->value));
	if ((*format)->type == 'X')
		upper_string(result);
	if ((*format)->precision)
		common_precision(format, result);
	apply_format_width(format, result);
}
