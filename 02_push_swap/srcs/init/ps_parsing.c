/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:47:50 by hkwon             #+#    #+#             */
/*   Updated: 2021/05/26 22:19:39 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		ps_check_num(char *save)
{
	int		i;

	i = -1;
	if (save[i] == '-')
		i++;
	while (save[++i])
	{
		if (!ft_isdigit(save[i]))
			return (0);
	}
	return (1);
}

int		ps_check_int(char *save, long *num)
{
	if (!ps_check_num(save))
		return (0);
	*num = ft_ltoi(save);
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
		(*link)->next = new_link_next(*link, num);
		*link = (*link)->next;
	}
}

t_link	*ps_start(char *av[], t_info *info)
{
	t_link	*link;
	char	**save;
	int		i,j;
	long	num;

	i = 0;
	link = 0;
	num = 0;
	while (av[++i])
	{
		save = ft_split(av[i], ' ');
		j = -1;
		while (save[++j])
		{
			if (!ps_check_int(save[j], &num))
				ps_link_free(&link);
			ps_link_create(&link, num);
		}
	}
	return (link);
}
