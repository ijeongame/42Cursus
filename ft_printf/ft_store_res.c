/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:37:53 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/04 22:49:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_res_char(char **res, char c)
{
	if (res)
	{
		**res = c;
		(*res)++;
	}
	else
		ft_putchar_fd(c, 1);
}

void	ft_res_str(char **res, char *s)
{
	if (res)
	{
		while (*s)
		{
			**res = *s;
			++(*res);
			++s;
		}
	}
	else
		ft_putstr_fd(s, 1);
}
