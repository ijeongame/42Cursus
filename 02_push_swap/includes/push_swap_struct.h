/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:35:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/29 22:18:24 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct		s_link
{
	long			val;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_flag
{
	int				cnt_ra;
	int				cnt_rb;
	int				cnt_pa;
	int				cnt_pb;
}					t_flag;

typedef struct		s_info
{
	long			max;
	long			min;
	long			pivot[2];
	int				pos;
	t_link			*a;
	int				a_size;
	t_link			*b;
	int				b_size;
}					t_info;

#endif
