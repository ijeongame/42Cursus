/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/01/15 16:48:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_parse_width(va_list ap, const char **format, t_format *op)
{
	int	s_width;

	s_width = 0;
	if (**format == '*')
	{
		if ((s_width = va_arg(ap, int)) < 0)
			s_width = -s_width;
		++(*format);
	}
	else
	{
		while (ft_isdigit(**format))
		{
			s_width *= 10;
			s_width += **format - '0';
			++(*format);
		}
	}
	op->width = s_width;
	return (ft_parse_format(ap, format, op));
}
