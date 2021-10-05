/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:46:25 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/05 17:59:22 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_onoff(char line, int *s_q, int *d_q)
{
	if (line == 39)
	{
		if (*s_q == 0)
			*s_q = 1;
		else if (*s_q == 1)
			*s_q = 0;
	}
	else if (line == 34)
	{
		if (*d_q == 0)
			*d_q = 1;
		else if (*d_q == 1)
			*d_q = 0;
	}
}

void	count_quote(char *line, int *i)
{
	int	s_q;
	int	d_q;

	(*i)++;
	s_q = 0;
	d_q = 0;
	while (line[*i])
	{
		if (line[*i] == 34 || line[*i] == 39)
			quote_onoff(line[*i], &s_q, &d_q);
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

char	*ft_strcpy_i_to_j(char *line, int i, int j)
{
	char	*result;
	int		k;

	if (!(result = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	k = 0;
	while (i < j)
		result[k++] = line[i++];
	result[k] = '\0';
	return (result);
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

char	**ft_parsing(char *line)
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
