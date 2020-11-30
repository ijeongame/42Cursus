/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:33:04 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/30 21:36:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_format_parse(va_list ap, const char **format)
{
	t_format *flist;

	if (!(flist = ft_init_flist(format)))
		return (-1);
	if (ft_strchr("-0+# ", **format))
		ft_flag_parse();
	if (ft_strchr("123456789*", **format))
		ft_width_parse();
	if (ft_strchr(".", **format))
		ft_prec_parse();
	if (ft_strchr("cspdiuxXnfgeo%", **format))
		ft_type_parse();
}
