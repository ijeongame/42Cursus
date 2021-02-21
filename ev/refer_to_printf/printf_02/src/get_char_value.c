/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:20 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:17:01 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	apply_char_width(t_format **format, int *total_letter)
{
	int idx;
	int empty_width;

	idx = 0;
	empty_width = (*format)->width - 1;
	if ((*format)->flag & FLAG_DASH)
	{
		write(1, (*format)->value, 1);
		while (idx++ < empty_width)
			write(1, " ", 1);
	}
	else if ((*format)->flag & FLAG_ZERO && !(*format)->precision)
	{
		while (idx++ < empty_width)
			write(1, "0", 1);
		write(1, (*format)->value, 1);
	}
	else
	{
		while (idx++ < empty_width)
			write(1, " ", 1);
		write(1, (*format)->value, 1);
	}
	if (0 < empty_width)
		(*total_letter) += empty_width;
}

void	get_char_value(va_list ap, t_format **format, int *total_letter)
{
	(*format)->value = (char*)malloc(sizeof(char));
	*((int*)(*format)->value) = va_arg(ap, int);
	if ((*format)->value)
	{
		apply_char_width(format, total_letter);
		(*total_letter)++;
	}
}
