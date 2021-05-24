/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:00:22 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 23:26:55 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_len(unsigned long long n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_convert_base(unsigned long long n, char *convert)
{
	unsigned long long	nbr;
	char				*res;
	int					len;
	int					base;

	base = ft_strlen(convert);
	len = ft_base_len(n, base);
	nbr = n;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (--len > 0 && nbr != 0)
	{
		res[len] = convert[nbr % base];
		nbr /= base;
	}
	res[0] = convert[nbr % base];
	return (res);
}
