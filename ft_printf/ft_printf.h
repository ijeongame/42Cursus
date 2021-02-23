/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/02/23 20:32:44 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft.h"

typedef struct			s_format{
	int			left;
	int			zero;
	int			sign;
	int			width;
	int			prec;
	int			type;
}						t_format;

int						ft_printf(const char *format, ...);
void			ft_init_list(t_format *op);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *ptr, int value, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

int		ft_putchar(char c);
int		ft_putstr(char *s);

char					*ft_lltoa(long long n);

int						ft_print_int(va_list ap, t_format *op);
int						ft_print_un_int(va_list ap, t_format *op);
int						ft_print_char(va_list ap, t_format *op);

#endif
