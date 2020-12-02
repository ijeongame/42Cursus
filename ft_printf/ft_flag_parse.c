/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:53:30 by hkwon             #+#    #+#             */
/*   Updated: 2020/12/02 19:10:00 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_flag_parse(const char **format, t_format *op)
{
	if (**format == '-')
		op->flag.left = 1;
	if (**format == '0')
		op->flag.zero = 1;
	if (**format == '#')
		op->flag.base = 1;
	if (**format == ' ')
		op->flag.space = 1;
	if (**format == '+')
		op->flag.sign = 1;
	return (0);
}