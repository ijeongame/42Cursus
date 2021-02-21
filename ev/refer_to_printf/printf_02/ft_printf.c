/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmyungjin <jungmyungjin@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:17:03 by jungmyungjin      #+#    #+#             */
/*   Updated: 2021/01/10 21:48:57 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

t_format	*format_checker(char *str, int *cnt, va_list ap)
{
	t_format *format;

	format = (t_format*)malloc(sizeof(t_format));
	format->flag = 0;
	format->width = 0;
	format->precision = NULL;
	format->type = '\0';
	format->size = NULL;
	format->value = NULL;
	format->value_sign = NULL;
	format->value_is_neg = NULL;
	(*cnt)++;
	format->flag = check_flag(str, cnt);
	format->width = check_width(str, cnt, ap, &format);
	format->precision = check_precision(str, cnt, ap);
	format->size = check_size(str, cnt);
	format->type = check_type(str, cnt);
	(*cnt)--;
	return (format);
}

int			ft_printf(const char *str, ...)
{
	int			idx;
	int			total_letter;
	t_format	*format;
	va_list		ap;

	idx = 0;
	total_letter = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			format = format_checker((char*)str, &idx, ap);
			total_letter += get_value_by_type(ap, &format, &total_letter);
			free_format(&format);
		}
		else
		{
			write(1, &str[idx], 1);
			total_letter++;
		}
		idx++;
	}
	va_end(ap);
	return (total_letter);
}
