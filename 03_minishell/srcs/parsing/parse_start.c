/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:15:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/07 00:38:21 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*make_cmd(char *cmd_list)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)ft_malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->token = parse_token(cmd_list);
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_cmd	*make_cmd_set(char **cmd_list)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;

	i = 0;
	cmd = NULL;
	while (cmd_list[i])
	{
		tmp = make_cmd(cmd_list[i]);
		if (!tmp)
			return (NULL);
		if (cmd == NULL)
			cmd = tmp;
		else
		{
			cmd->next = tmp;
			tmp->prev = cmd;
			cmd = cmd->next;
		}
		i++;
	}
	ft_free_array(cmd_list);
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}

t_cmd	*parse_start(char *line)
{
	char	**cmd_list;
	t_cmd	*tmp;

	if (!line)
		return (NULL);
	cmd_list = parse_line(line);
	// debug
	int i = -1;
	while (cmd_list[++i])
		printf("cmd list check after parsing : %s\n", cmd_list[i]);
	if (!cmd_list)
		return (NULL);
	return (make_cmd_set(cmd_list));
}
