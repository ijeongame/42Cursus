/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwonhyukbae <kwonhyukbae@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:45:48 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/04 14:49:44 by kwonhyukbae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// | 로 들어왔을 때 파싱해서 저장하는 게 필요할 것 같아요.
static char	*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

static void	run_shell(char *line, char **en)
{
	int	i;

	i = -1;
	while (++i < BLTIN_NUM)
		if (!ft_strcmp(line, blt_str(i)))
			(*blt_func(i))(line, en);
}

void	minishell(char **en)
{
	int		status;
	char	*line;
	char	**cmd;

	status = 1;
	while (status)
	{
		write(1, "minishell>", ft_strlen("minishell>"));
		line = read_line();
		run_shell(line, en);
		// if (exit)
		// 	status = 0;
	}
	(void)en;
}
