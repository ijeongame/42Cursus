/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 05:30:24 by hkwon             #+#    #+#             */
/*   Updated: 2021/06/01 15:35:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		check_init(t_link **a, t_link **b, t_info *info);
void	check_run_swap(t_link **a, t_link **b, t_info *info, char *line);
void	check_run_rot_up(t_link **a, t_link **b, t_info *info, char *line);
void	check_run_rot_down(t_link **a, t_link **b, t_info *info, char *line);
void	check_run_push(t_link **a, t_link **b, t_info *info, char *line);

#endif
