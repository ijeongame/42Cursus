/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:27:41 by hkwon             #+#    #+#             */
/*   Updated: 2021/07/31 18:45:08 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += *str++ - '0';
	}
	return (res * sign);
}

static int	cnt_num(int n)
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

static void	write_num(char *dest, unsigned int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		write_num(dest - 1, n / 10);
	}
}

char	*change_num(int len, int n, int nbr)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		write_num((res + len - 1), -nbr);
	}
	else
		write_num((res + len - 1), nbr);
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nbr;
	int				len;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
			len = cnt_num(n) + 1;
		else
			len = cnt_num(n);
		res = change_num(len, n, nbr);
	}
	return (res);
}
