/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:02:42 by inshin            #+#    #+#             */
/*   Updated: 2021/01/08 17:20:26 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int n)
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

int		ft_itoa_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			num_len;
	int			sign;
	long long	nbr;

	num_len = ft_numlen(n);
	sign = ft_itoa_sign(n);
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
