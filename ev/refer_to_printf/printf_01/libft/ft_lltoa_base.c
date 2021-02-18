/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:53:53 by inshin            #+#    #+#             */
/*   Updated: 2021/01/11 17:34:26 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len_base(unsigned long long n, int base_len)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char		*ft_lltoa_base(unsigned long long n, char *base)
{
	char				*str;
	int					num_len;
	int					base_len;
	unsigned long long	nbr;

	base_len = ft_strlen(base);
	num_len = ft_num_len_base(n, base_len);
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	if (!(str = (char *)malloc(sizeof(char) * (num_len + 1))))
		return (NULL);
	str[num_len] = '\0';
	while (--num_len > 0 && nbr != 0)
	{
		str[num_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	str[0] = base[nbr % base_len];
	return (str);
}
