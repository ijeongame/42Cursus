/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:19:54 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/11 21:54:51 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*init_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = 0;
	token->arg = NULL;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

static void	connect_token_list(t_token **token, t_token **tmp)
{
	if (!(*token))
		(*token) = (*tmp);
	else
	{
		(*token)->next = *tmp;
		(*tmp)->prev = *token;
		*token = (*token)->next;
	}
}

static void	make_token_redirect(t_token **res, char *args)
{
	if (args[0] == '<' && args[1] != '<')
	{
		(*res)->type = RD_IN;
		(*res)->arg = ft_strtrim(args, "<");
	}
	else if (args[0] == '>' && args[1] != '>')
	{
		(*res)->type = RD_OUT;
		(*res)->arg = ft_strtrim(args, ">");
	}
	else if (args[0] == '>' && args[1] == '>')
	{
		(*res)->type = RD_APPEND;
		(*res)->arg = ft_strtrim(args, ">>");
	}
	else if (args[0] == '<' && args[1] == '<')
	{
		(*res)->type = RD_HEREDOC;
		(*res)->arg = ft_strtrim(args, "<<");
	}
}

static t_token	*make_token(char *args, int cmd_flag)
{
	t_token	*res;

	res = init_token();
	if (!res)
		return (NULL);
	if (args[0] == '<' || args[0] == '>')
		make_token_redirect(&res, args);
	else
	{
		if (!cmd_flag)
			res->type = COMMAND;
		else
			res->type = ARGUMENT;
		res->arg = ft_strdup(args);
	}
	return (res);
}

t_token	*make_token_list(char **args)
{
	t_token	*token;
	t_token	*tmp;
	int		i;
	int		cmd_flag;

	i = -1;
	cmd_flag = 0;
	token = NULL;
	while (args[++i])
	{
		tmp = make_token(args[i], cmd_flag);
		if (tmp->type == COMMAND)
			cmd_flag = 1;
		connect_token_list(&token, &tmp);
	}
	ft_free_arr(args);
	while (token->prev)
		token = token->prev;
	return (token);
}
