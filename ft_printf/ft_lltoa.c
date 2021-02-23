/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:36:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 20:28:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cnt_num(long long n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void		write_num(char *dest, unsigned long long n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		write_num(dest - 1, n / 10);
	}
}

char			*ft_lltoa(long long n)
{
	char				*res;
	unsigned long long	nbr;
	int					len;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		len = n < 0 ? cnt_num(n) + 1 : cnt_num(n);
		if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		if (n < 0)
		{
			res[0] = '-';
			write_num((res + len - 1), -nbr);
		}
		else
			write_num((res + len - 1), nbr);
		res[len] = '\0';
	}
	return (res);
}
