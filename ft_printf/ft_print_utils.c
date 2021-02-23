/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:03:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 20:32:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list(t_format *op)
{
	op->left = 0;
	op->zero = 0;
	op->sign = 0;
	op->width = 0;
	op->prec = -1;
	op->type = ' ';
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (char *)str;
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*res;

	res = (unsigned char *)ptr;
	while (size--)
		*res++ = value;
	return (ptr);
}


void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	size_t				i;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}

static int		cnt_num(int n)
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

static void		write_num(char *dest, unsigned int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		write_num(dest - 1, n / 10);
	}
}

char			*ft_itoa(int n)
{
	char			*res;
	unsigned int	nbr;
	int				len;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) + (len1 + len2 + 1))))
		return (0);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
