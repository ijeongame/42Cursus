/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:56:52 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/30 16:22:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_array(char ***array)
{
	int		i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free((*array));
	return (0);
}

void	free_link(t_link **link)
{
	t_link	*tmp_link;

	while (*link)
	{
		if ((*link)->next)
			tmp_link = (*link)->next;
		else
			tmp_link = 0;
		free(*link);
		(*link) = tmp_link;
	}
}

void	free_exit(t_link **link)
{
	ft_putstr_fd("Error\n", 1);
	*link = move_link_head(*link);
	free_link(link);
	exit(0);
}
