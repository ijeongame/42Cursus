/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <myung2667@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:26:48 by mjung             #+#    #+#             */
/*   Updated: 2021/01/10 21:47:52 by jungmyungjin     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
{
	int		index;
	int		sign;
	long	result;

	result = 0;
	index = 0;
	sign = 1;
	while (is_blank(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index++] == '-')
			sign = -1;
	}
	while (nptr[index] != '\0')
	{
		if (nptr[index] < '0' || '9' < nptr[index])
			break ;
		result = (result * 10) + (nptr[index++] - '0');
		if (INT_MAX < (sign * result))
			return (-1);
		if (INT_MIN > (sign * result))
			return (0);
	}
	return ((int)result * sign);
}
