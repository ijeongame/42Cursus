/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:08:19 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:24:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "push_swap.h"

t_link	*move_stat(t_link *link);
t_link	*new_link_head(t_link *link, long value);
t_link	*new_link_tail(t_link *link, long value);
void	delete_link(t_link *link);

#endif
