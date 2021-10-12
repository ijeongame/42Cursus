/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:05:58 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/27 18:12:43 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	count_word(const char *cmd, int *i, int *cnt)
{
	if (cmd[*i] == '\'')
	{
		(*i)++;
		while (cmd[*i] != '\'' && cmd[*i] != '\0')
			(*i)++;
		(*cnt)++;
	}
	else if (cmd[*i] == '\"')
	{
		(*i)++;
		while (cmd[*i] != '\"' && cmd[*i] != '\0')
			(*i)++;
		(*cnt)++;
	}
	else
	{
		while (cmd[*i] != ' ' && cmd[*i] != '\0')
			(*i)++;
		(*cnt)++;
	}
}

int	count_parse(const char *cmd)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != ' ')
			count_word(cmd, &i, &cnt);
		if (cmd[i] == '\0')
			break ;
		else
			i++;
	}
	return (cnt);
}

char	**make_cmd(char *cmd, char **res, t_parse *parse)
{
	parse->i = 0;
	parse->j = 0;
	while (cmd[parse->i] && parse->j < parse->len)
	{
		parse->k = 0;
		if (cmd[parse->i] != ' ')
		{
			if (cmd[parse->i] == '\'')
				s_quote(cmd, res, parse);
			else if (cmd[parse->i] == '\"')
				d_quote(cmd, res, parse);
			else
				space(cmd, res, parse);
		}
		res[parse->j][parse->k] = '\0';
		parse->i++;
		parse->j++;
	}
	res[parse->j] = NULL;
	return (res);
}

char	**ft_parsing(char *cmd)
{
	t_parse	parse;

	if (cmd == NULL)
		return (NULL);
	parse.len = count_parse(cmd);
	parse.pstr = (char **)malloc(sizeof(char *) * (parse.len + 1));
	if (!parse.pstr)
		return (NULL);
	return (make_cmd(cmd, parse.pstr, &parse));
}
