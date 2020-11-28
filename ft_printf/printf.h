/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:54:17 by hkwon             #+#    #+#             */
/*   Updated: 2020/11/28 21:33:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//list에 들어가면 좋을만한 옵션을 정하는 것이 중요.
//1. create flag list
typedef struct	s_flag{
	int			left;
	int			sign;
	int			space;
	int			base;
	int			zero;
}				t_flag;

//2. create format list
typedef struct s_format{
	t_flag		flag;
	int			width;
	int			prec;
	int			type;
}				t_format;

int				ft_printf(const char *format, ...);
void			ft_print_int(va_list ap, const char **format);
int				ft_format_parse(const char *format);
int				ft_flag_parse();

#endif
