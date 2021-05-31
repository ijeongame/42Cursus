/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:22:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/31 23:28:30 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_ALGO_H
# define PUSH_SWAP_ALGO_H

# include "push_swap_struct.h"

void	algo_init(t_link **a, t_link **b, t_info *info);
void	algo_less(t_link **a, t_link **b, t_info *info);
void	algo_three_sort(t_link **a, t_link **b, t_info *info);
void	algo_handle_a(t_link **a, t_link **b, t_info *info);
void	algo_handle_b(t_link **a, t_link **b, t_info *info);
void	algo_a_to_b(t_link **a, t_link **b, t_info *info, int cnt);
void	algo_b_to_a(t_link **a, t_link **b, t_info *info, int cnt);

#endif
