/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:11:43 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/10/02 17:42:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *line, char **en)
{
	int		i;
	char	**temp;
	char	**buff;

	buff = ft_split(line, ' ');
	i = 0;
	while (buff[i])
		i++;
	temp = (char **)malloc(sizeof(char *) * i);
	i = -1;
	while (buff[++i])
		temp[i] = buff[i];
	temp[i] = NULL;
	if (execve("/bin/echo", temp ,en) == -1)
		fprintf(stderr, "에러 %s\n", strerror(errno));
	return (0);
}
