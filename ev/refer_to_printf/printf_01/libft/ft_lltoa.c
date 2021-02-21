/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:12:00 by inshin            #+#    #+#             */
/*   Updated: 2021/01/11 17:31:14 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ft_lltoa_sign(long long n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char		*ft_lltoa(long long n)
{
	char		*str;
	int			num_len;
	int			sign;
	long long	nbr;

	num_len = ft_num_len(n);
	sign = ft_lltoa_sign(n);
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	if (!(str = (char *)malloc(sizeof(char) * (num_len + 1))))
		return (NULL);
	str[num_len] = '\0';
	while (--num_len > 0 && nbr != 0)
	{
		str[num_len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	else
		str[0] = nbr % 10 + '0';
	return (str);
}
