/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_by_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:35 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 22:40:18 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_value_by_type(va_list ap, t_format **format, int *total_letter)
{
	char	*result;
	int		len_result;

	result = NULL;
	if (ft_strchr("di", (*format)->type))
		get_int_value(ap, format, &result);
	else if (ft_strchr("uxX", (*format)->type))
		get_uint_value(ap, format, &result);
	else if (ft_strchr("c", (*format)->type))
		get_char_value(ap, format, total_letter);
	else if (ft_strchr("s", (*format)->type))
		get_string_value(ap, format, total_letter);
	else if (ft_strchr("p", (*format)->type))
		get_pointer_value(ap, format, &result);
	else if (ft_strchr("%", (*format)->type))
		get_percent_value(format, &result);
	len_result = ft_strlen(result);
	if (result)
	{
		write(1, result, len_result);
		free_string(&result);
	}
	return (len_result);
}
