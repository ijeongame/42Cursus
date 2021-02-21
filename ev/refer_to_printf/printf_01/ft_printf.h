/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inshin <inshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:51:21 by inshin            #+#    #+#             */
/*   Updated: 2021/01/11 17:33:43 by inshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_info
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	char	type;
}				t_info;

# define ERROR -1
# define TYPE "cspdiuxX%"
# define HEXLOW "0123456789abcdef"
# define HEXUPPPER "0123456789ABCDEF"

/*
** ft_printf.c
*/
int				ft_printf(const char *fmt, ...);

/*
** ft_printf_utils.c
*/
void			init_info(t_info *info);
void			pre_star(t_info *info);
int				ft_putchar(char c);
int				ft_putstr(char *s);

/*
** print_function
*/
int				print_percent(t_info *info);
int				print_char(va_list ap, t_info *info);
int				print_str(va_list ap, t_info *info);
int				print_nbr(va_list ap, t_info *info);

#endif
