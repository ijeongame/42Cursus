/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/12 21:47:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_format_parse(va_list ap, const char **format)
{
	t_format *op;

	if (!(op = ft_init_flist(format)))
		return (-1);
	if (ft_strchr("-0# +", **format))
		ft_flag_parse(**format, op);
	if (ft_strchr("123456789*", **format))
		ft_width_parse(ap, **format, op);
	if (ft_strchr(".", **format))
		ft_prec_parse();
	if (ft_strchr("cspdiuxXnfgeo%", **format))
		ft_type_parse(ap, **format, op);
	return (ft_format_parse(ap, op));
}
