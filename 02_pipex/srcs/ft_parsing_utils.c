/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:35:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/26 21:21:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parse_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	s_quote(char *cmd, char **res, t_parse *parse)
{
	int	len;

	parse->i++;
	len = ft_parse_len(cmd, '\'', parse->i);
	res[parse->j] = malloc(sizeof(char) * (len + 1));
	if (!res)
		return ;
	while (cmd[parse->i] != '\0' && cmd[parse->i] != '\'')
		res[parse->j][parse->cnt++] = cmd[parse->i++];
}

void	d_quote(char *cmd, char **res, t_parse *parse)
{
	int	len;

	parse->i++;
	len = ft_parse_len(cmd, '\"', parse->i);
	res[parse->j] = malloc(sizeof(char) * (len + 1));
	if (!res)
		return ;
	while (cmd[parse->i] != '\0' && cmd[parse->i] != '\"')
		res[parse->j][parse->cnt++] = cmd[parse->i++];
}

void	space(char *cmd, char **res, t_parse *parse)
{
	int	len;

	len = ft_parse_len(cmd, ' ', parse->i);
	res[parse->j] = malloc(sizeof(char) * (len + 1));
	if (!res)
		return ;
	while (cmd[parse->i] != '\0' && cmd[parse->i] != ' ')
		res[parse->j][parse->cnt++] = cmd[parse->i++];
}
