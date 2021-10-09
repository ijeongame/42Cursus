/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:32:48 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/08 14:22:23 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	args_redirect_arr(char *cmd_list, int *index, int *flag)
{
	if (cmd_list[*index] == '<' && cmd_list[*index + 1] != '<')
		*flag |= RD_IN;
	else if (cmd_list[*index] == '>' && cmd_list[*index + 1] != '>')
		*flag |= RD_OUT;
	else if (cmd_list[*index] == '>' && cmd_list[*index + 1] == '>')
	{
		*flag |= RD_APPEND;
		(*index)++;
	}
	else if (cmd_list[*index] == '<' && cmd_list[*index + 1] == '<')
	{
		*flag |= RD_HEREDOC;
		(*index)++;
	}
	(*index)++;
}

static void	args_join_redirect(char **args, int *index, int *flag)
{
	if (*flag & RD_IN)
	{
		args[*index] = ft_strjoin_free("<", args[*index], 2);
		*flag ^= RD_IN;
	}
	if (*flag & RD_OUT)
	{
		args[*index] = ft_strjoin_free(">", args[*index], 2);
		*flag ^= RD_OUT;
	}
	if (*flag & RD_APPEND)
	{
		args[*index] = ft_strjoin_free(">>", args[*index], 2);
		*flag ^= RD_APPEND;
	}
	if (*flag & RD_HEREDOC)
	{
		args[*index] = ft_strjoin_free("<<", args[*index], 2);
		*flag ^= RD_HEREDOC;
	}
	(*index)++;
}

static void	args_quote_arr(char *cmd_list, int *index, int *flag)
{
	if (cmd_list[*index] == '\"' && !(*flag & D_QUOTE))
	{
		*flag |= D_QUOTE;
		while (*flag & D_QUOTE)
		{
			(*index)++;
			if (cmd_list[*index] == '\\')
				*index += 2;
			if (cmd_list[*index] == '\"')
				*flag ^= D_QUOTE;
		}
	}
	else if (cmd_list[*index] == '\'')
	{
		while (cmd_list[++(*index)] != '\'')
			;
	}
	(*index)++;
}

/*
** index[3] == i, j, k;
*/
char	**parse_token_arr(char **args, char *cmd_list)
{
	int	index[3];
	int	flag;

	ft_memset(index, 0, sizeof(index));
	flag = 0;
	while (cmd_list[index[0]])
	{
		if (!ft_strchr("<>\t\n ", cmd_list[index[0]]))
		{
			index[1] = index[0];
			while (!ft_strchr("<>\t\n ", cmd_list[index[1]]) \
				&& cmd_list[index[1]])
				args_quote_arr(cmd_list, &index[1], &flag);
			args[index[2]] = ft_strcpy_i_to_j(cmd_list, index[0], index[1]);
			args_join_redirect(args, &index[2], &flag);
			if (!cmd_list[index[1]])
				break ;
			index[0] = index[1];
		}
		else
			args_redirect_arr(cmd_list, &index[0], &flag);
		//debug
		printf("index[0] check in token list argument : %d\n", index[0]);
		printf("index[1] check in token list argument : %d\n", index[1]);
		printf("index[2] check in token list argument : %d\n", index[2]);
		printf("==========================================\n");
		//end
	}
	args[index[2]] = NULL;
	//debug
	index[2] = -1;
	while (args[++index[2]])
		printf("arument check atfer copy : %s\n", args[index[2]]);
	printf("==========================================\n");
	//end
	return (args);
}
