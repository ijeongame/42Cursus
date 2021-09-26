/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:15:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/26 17:04:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strskip(char **str, char *ch_cntet)
{
	if (!(*str))
		return ;
	while (**str && ft_strchr(ch_cntet, **str))
		++(*str);
}

// Add quote check
// static void	quote_onoff(char *line, int *s_quote, int *d_quote, int i)
// {
// 	if (*line == '\'')
// 	{
// 		if (*s_quote == OFF)
// 			*s_quote = ON;
// 		else if (*s_quote == ON)
// 			*s_quote = OFF;
// 	}
// 	else if (*line == '\"')
// 	{
// 		if (i == 0 || (*d_quote == OFF && *(line - 1) != '\\'))
// 			*d_quote = ON;
// 		else if (*d_quote == ON && *(line - 1) != '\\')
// 			*d_quote = OFF;
// 	}
// }

int	ft_count(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		while (line && (line[i] == '|' || \
			ft_isalpha(line[i]) || ft_isdigit(line[i])))
			i++;
		cnt++;
		while (line[i] && ft_strchr(" \t\n", line[i]))
			i++;
	}
	return (cnt);
}

int	ft_ch_count(char *line)
{
	int	cnt;

	cnt = -1;
	while (line[++cnt])
	{
		if (ft_strchr(" \t\n", line[cnt]))
			return (cnt);
	}
	return (cnt);
}

t_cmd	*cmd_init(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	// cmd->name = ft_strdup("");
	cmd->type = 0;
	cmd->arg = NULL;
	cmd->prev = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	rd_or_pipe(char *cmd_list, t_cmd **res)
{
	if (cmd_list[0] == '|')
	{
		(*res)->type = PIPE;
		(*res)->arg = ft_strdup(cmd_list);
	}
	else if (cmd_list[0] == '<')
	{
		(*res)->type = RD_IN;
		(*res)->arg = ft_strdup(cmd_list);
	}
	else if (cmd_list[0] == '>' && cmd_list[1] != '>')
	{
		(*res)->type = RD_OUT;
		(*res)->arg = ft_strdup(cmd_list);
	}
	else if (cmd_list[0] == '>' && cmd_list[1] == '>')
	{
		(*res)->type = RD_APPEND;
		(*res)->arg = ft_strdup(cmd_list);
	}
}

t_cmd	*cmd_check(char *cmd_list, int cmd_flag)
{
	t_cmd	*res;

	res = cmd_init();
	if (!res)
		return (0);
	if (ft_strchr("<>|", cmd_list[0]))
		rd_or_pipe(cmd_list, &res);
	else
	{
		if (cmd_flag == 0)
			res->type = CMD;
		else
			res->type = ARG;
		res->arg = ft_strdup(cmd_list);
		printf("res argument check : %s\n", res->arg);
	}
	return (res);
}

void	make_cmd_list(t_cmd **cmd, t_cmd **tmp)
{
	if (!(*cmd))
		(*cmd) = (*tmp);
	else
	{
		(*cmd)->next = *tmp;
		(*tmp)->prev = *cmd;
		*cmd = (*cmd)->next;
	}
}

t_cmd	*make_cmd_set(char **cmd_list)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;
	int		cmd_flag;

	i = 0;
	cmd_flag = 0;
	while (cmd_list[i])
	{
		tmp = cmd_check(cmd_list[i], cmd_flag);
		if (tmp->type == CMD)
			cmd_flag = 1;
		make_cmd_list(&cmd, &tmp);
		free(cmd_list[i]);
		i++;
	}
	free(cmd_list);
	while (cmd->prev)
	{
		printf("token list check : %s\n", cmd->arg);
		cmd = cmd->prev;
	}
	printf("token list check : %s\n", cmd->arg);
	return (cmd);
}

t_mini	*parse(char	*line)
{
	char	**cmd_list;
	int		i;
	int		j;
	int		cnt;
	int		ch_cnt;
	t_cmd	*tmp;

	if (!line)
		return (NULL);
	ft_strskip(&line, " \t\n");
	cnt = ft_count(line);
	cmd_list = (char **)malloc(sizeof(char *) * (cnt + 1));
	printf("cnt = %d\n", cnt);
	i = -1;
	while (++i < cnt)
	{
		printf("===========\n");
		printf("while start\n");
		j = -1;
		ch_cnt = ft_ch_count(line);
		printf("ch_cnt check : %d\n", ch_cnt);
		cmd_list[i] = ft_strnew(ch_cnt);
		printf("line check before input : %s\n", line);
		while (*line && !ft_strchr(" \t\n", *line) && ++j < ch_cnt)
		{
			cmd_list[i][j] = *line;
			line++;
			printf("cmd_list[%d][%d] check : %c\n", i, j, cmd_list[i][j]);
		}
		cmd_list[i][j + 1] = '\0';
		ft_strskip(&line, " \t\n");
		printf("skip after line : %s\n", line);
		if (!line)
			return (NULL);
	}
	cmd_list[cnt] = NULL;
	printf("===========\n");
	printf("finish while\n");
	i = -1;
	while (cmd_list[++i])
		printf("cmd_list check : %s\n", cmd_list[i]);
	tmp = (t_cmd *)malloc(sizeof(t_cmd));
	tmp = make_cmd_set(cmd_list);
	// while (tmp)
	// {
	// 	printf("token list check : %s\n", tmp->arg);
	// 	tmp = tmp->next;
	// }
	return (NULL);
}
