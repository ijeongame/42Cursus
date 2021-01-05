/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/18 20:03:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_parse_format(va_list ap, const char **format)
{
	t_format *op;

	if (!(op = ft_init_flist(format)))
		return (-1);
	if (ft_strchr("-0# +", **format))
		ft_parse_flag(**format, op);
	if (ft_strchr("123456789*", **format))
		ft_parse_width(ap, **format, op);
	if (ft_strchr(".", **format))
		ft_parse_prec(ap, op);
	if (ft_strchr("cspdiuxXnfgeo%", **format))
		ft_parse_type(ap, **format, op);
	return (ft_format_parse(ap, op));
}
