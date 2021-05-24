/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:15:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/24 23:52:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap_op.h"

typedef struct		s_lst
{
	long			val;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_info
{

}					t_info;



#endif
