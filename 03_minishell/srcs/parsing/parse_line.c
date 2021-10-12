/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:46:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/11 21:54:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** single quote ascii number 39
** double quote ascii number 34
** "" 안의 ""를 처리를 해줄 것 인가?
** echo "\"hello\"" -> "hello"
** echo "\'hello\' -> 'hello'
*/
static void	quote_onoff(char *line, int *s_q, int *d_q, int i)
{
	if (*line == 39)
	{
		if (*s_q == 0)
			*s_q = 1;
		else if (*s_q == 1)
			*s_q = 0;
	}
	else if (*line == 34)
	{
		if (i == 0 || (*d_q == 0 && *(line - 1) != '\\'))
			*d_q = 1;
		else if (*d_q == 1 && *(line - 1) != '\\')
			*d_q = 0;
	}
}

static void	count_quote(char *line, int *i)
{
	int	s_q;
	int	d_q;

	(*i)++;
	s_q = 0;
	d_q = 0;
	while (line[*i])
	{
		if (line[*i] == 34 || line[*i] == 39)
			quote_onoff(&(line[*i]), &s_q, &d_q, *i);
		if (line[*i] == '|' && (s_q == 0 && d_q == 0))
			break ;
		(*i)++;
	}
}

int	count_parse(char *line)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = -1;
	cnt = 0;
	while (line[i])
	{
		count_quote(line, &j);
		i = j;
		cnt++;
	}
	return (cnt);
}

char	**make_cmd_array(char *line, char **res, t_parse *parse)
{
	parse->i = 0;
	parse->j = -1;
	parse->k = 0;
	while (parse->k < parse->cnt)
	{
		count_quote(line, &parse->j);
		res[parse->k] = ft_strcpy_i_to_j(line, parse->i, parse->j);
		parse->i = parse->j + 1;
		parse->k++;
	}
	return (res);
}

char	**parse_line(char *line)
{
	t_parse	parse;

	if (line == NULL)
		return (NULL);
	parse.cnt = count_parse(line);
	parse.pstr = (char **)malloc(sizeof(char *) * (parse.cnt + 1));
	if (!parse.pstr)
		return (NULL);
	parse.pstr[parse.cnt] = NULL;
	return (make_cmd_array(line, parse.pstr, &parse));
}
