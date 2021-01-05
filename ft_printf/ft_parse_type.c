/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:55:14 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/18 19:03:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_type(va_list ap, const char **format, t_format *op)
{
	if (**format == 'd' || **format == 'i')
		ft_print_int(ap, op, **format);
	if (**format == 'c')
		ft_print_char(ap, format);
	if (**format == 's')
		ft_print_str(ap, format);
	if (**format == 'p')
	if (**format == 'u')
	if (**format == 'x' || **format == 'X')
	if (**format == 'n')
	if (**format == 'f' || **format == 'e' || **format == 'g')
	if (**format == 'o')
	if (**format == '%')
}