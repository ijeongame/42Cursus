/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:22 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:56:51 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	dec_precision(t_format **format, char **result)
{
	int		empty_width;
	char	*add_str;
	int		len_value;

	if (*(*format)->precision < 0)
	{
		free((*format)->precision);
		(*format)->precision = NULL;
		return ;
	}
	if (*(*format)->precision <= 0 && *(int*)(*format)->value == 0)
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

void	get_int_value(va_list ap, t_format **format, char **result)
{
	(*format)->value = (int*)malloc(sizeof(int));
	*((int*)(*format)->value) = va_arg(ap, int);
	(*format)->value_is_neg = (int*)malloc(sizeof(int));
	if (*((int*)(*format)->value) < 0)
		*(*format)->value_is_neg = 1;
	else
		*(*format)->value_is_neg = 0;
	*result = apply_sign(format, ft_itoa(*(int*)(*format)->value));
	if ((*format)->precision)
		dec_precision(format, result);
	apply_format_width(format, result);
}
