/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:20:42 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/01 15:52:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_num(int n)
{
	size_t cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	if (n > 0)
		return (cnt);
	else
		return (cnt + 1);
}

static void		*write_num(char *dest, unsigned int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		write_num(dest - 1, n / 10);
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*res;
	size_t			len;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		len = cnt_num(n);
		if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		if (n < 0)
		{
			res[0] = '-';
			write_num(res + len - 1, -nbr);
		}
		else
			write_num(res + len - 1, nbr);
		res[len] = '\0';
	}
	return (res);
}
