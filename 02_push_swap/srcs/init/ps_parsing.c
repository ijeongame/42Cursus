/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:47:50 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/28 17:20:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_check_num(char *save)
{
	int		i;

	i = 0;
	if (save[i] == '-')
		i++;
	while (save[i])
	{
		if (!ft_isdigit(save[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ps_check_int(char *save, long *num)
{
	if (!ps_check_num(save))
		return (0);
	*num = ft_atol(save);
	if (*num > INT_MAX || *num < INT_MIN)
		return (0);
	return (1);
}

void	ps_link_create(t_link **link, long num)
{
	if (!(*link))
		*link = new_link_head(*link, num);
	else
	{
		(*link)->next = new_link_tail(*link, num);
		*link = (*link)->next;
	}
}

int		ps_create(t_link **link, char *av, t_info *info)
{
	char	**save;
	int		i;
	long	num;

	save = ft_split(av, ' ');
	i = -1;
	while (save[++i])
	{
		if (!ps_check_int(save[i], &num))
			return (free_array(&save));
		ps_link_create(link, num);
		free(save[i]);
		info->a_size++;
	}
	free(save);
	return (1);
}

t_link	*ps_start(char *av[], t_info *info)
{
	t_link	*link;
	int		i;

	i = 0;
	link = 0;
	while (av[++i])
	{
		if (!ps_create(&link, av[i], info))
			free_exit(&link);
	}
	if (!ps_check_overlap(link))
		free_exit(&link);
	return (link);
}
