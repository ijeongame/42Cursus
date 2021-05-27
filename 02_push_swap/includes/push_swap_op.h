/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:38:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:36:31 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_OP_H
# define PUSH_SWAP_OP_H

# include "push_swap_struct.h"

void	op_sa(t_link **a, t_info *info);
void	op_sb(t_link **b, t_info *info);
void	op_ss(t_link **a, t_link **b, t_info *info);

void	op_pa(t_link **a, t_link **b, t_info *info);
void	op_pb(t_link **a, t_link **b, t_info *info);

void	op_ra(t_link **a, t_info *info);
void	op_rb(t_link **b, t_info *info);
void	op_rr(t_link **a, t_link **b, t_info *info);

void	op_rra(t_link **a, t_info *info);
void	op_rrb(t_link **b, t_info *info);
void	op_rrr(t_link **a, t_link **b, t_info *info);

#endif
