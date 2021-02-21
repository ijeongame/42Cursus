/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:53:37 by inshin            #+#    #+#             */
/*   Updated: 2021/01/09 20:16:22 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->dot = 0;
	info->width = 0;
	info->precision = -1;
	info->type = ' ';
}

void	pre_star(t_info *info)
{
	if (info->width < 0)
	{
		info->minus = 1;
		info->width *= -1;
	}
	if (info->minus == 1)
		info->zero = 0;
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
