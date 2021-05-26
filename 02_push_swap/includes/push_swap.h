/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:15:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:24:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "push_swap_op.h"
# include "push_swap_utils.h"
# include "libft.h"

typedef struct		s_link
{
	long			val;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_info
{
	int				max;
	int				min;
	int				a_size;
	int				b_size;
}					t_info;

int		main(int ac, char *av[]);

t_link	*ps_start(char *av[], t_info *info);

#endif
