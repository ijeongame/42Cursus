/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:04:30 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/18 17:09:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ignore_sep(char *line)
{
	if (*line && *line == '\\' && *(line + 1) == ';')
		return (1);
	else if (*line && *line == '\\' && *(line + 1) == '|')
		return (1);
	else if (*line && *line == '\\' && *(line + 1) == '>')
		return (1);
	else if (*line && *line == '\\' && *(line + 1) == '>'\
			&& *(line + 2) == '>')
		return (1);
	return (0);
}

t_token	*next_token(char *line, int *i)
{
	t_token	*token;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	if (!(token = malloc(sizeof(t_token)))
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\' && (*i)++)
			token->name[j++] = line[(*i)++];
		else
			token->name[j++] = line[(*i)++];
	}
	token->name[j] = '\0';
	return (token);
}

t_token	*get_token(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		sep;

	prev = NULL;
	next = NULL;
	ft_nameskip(&line, " \t\n");
	while (line)
	{
		sep = ignore_sep(line);
	}
}
