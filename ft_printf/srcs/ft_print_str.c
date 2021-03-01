/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:40:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/03/01 23:01:26 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_res(char *tmp, int len, t_format *op)
{
	int		cnt;
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (op->width + 1))))
		return (0);
	res[op->width] = '\0';
	if (op->prec < 0 && op->zero && !op->left)
	{
		ft_memset(res, '0', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else if (!op->left)
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res + op->width - len, tmp, len);
	}
	else
	{
		ft_memset(res, ' ', op->width);
		ft_memcpy(res, tmp, len);
	}
	cnt = ft_putstr(res);
	free(res);
	return (cnt);
}

int			ft_print_str(va_list ap, t_format *op)
{
	int		cnt;
	int		len;
	char	*tmp;

	tmp = va_arg(cp, char *);
	if (!tmp)
		tmp = "(NULL)";
	len = ft_strlen(tmp);
	if (len > op->prec && op->prec > -1)
		len = op->prec;
	if (len > op->width)
		op->width = len;
	cnt = ft_print_res(tmp, len, op);
	return (cnt);
}