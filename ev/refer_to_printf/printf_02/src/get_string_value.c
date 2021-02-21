/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:31 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:35:38 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	write_str_width(t_format **format, int *len_max, int *empty_width)
{
	int idx_width;
	int idx_value;

	idx_width = 0;
	idx_value = 0;
	if ((*format)->flag & FLAG_DASH)
	{
		while (idx_value < *len_max)
			write(1, &((*format)->value)[idx_value++], 1);
		while (idx_width++ < *empty_width)
			write(1, " ", 1);
	}
	else
	{
		if ((*format)->flag & FLAG_ZERO && !(*format)->precision)
			while (idx_width++ < *empty_width)
				write(1, "0", 1);
		else
			while (idx_width++ < *empty_width)
				write(1, " ", 1);
		while (idx_value < *len_max)
			write(1, &((*format)->value)[idx_value++], 1);
	}
}

void	apply_str_width(t_format **format, int *total_letter)
{
	int empty_width;
	int len_max;

	len_max = ft_strlen((char*)(*format)->value);
	if ((*format)->precision && *(*format)->precision < len_max &&
	*(*format)->precision >= 0)
		len_max = *(*format)->precision;
	empty_width = (*format)->width - len_max;
	write_str_width(format, &len_max, &empty_width);
	if (0 < empty_width)
		(*total_letter) += empty_width;
	if (0 < len_max)
		(*total_letter) += len_max;
}

void	get_string_value(va_list ap, t_format **format, int *total_letter)
{
	(*format)->value = va_arg(ap, char*);
	if (!(char*)(*format)->value)
		(*format)->value = ft_strdup("(null)");
	else
		(*format)->value = ft_strdup((*format)->value);
	apply_str_width(format, total_letter);
}
