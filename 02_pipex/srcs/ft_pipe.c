/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:42:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/09/26 15:53:27 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe_exit(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	if (argc != 5)
		ft_pipe_exit("Check Argument: ./pipex file1 cmd1 cmd2 file2\n");
	ft_pipe_process(&info, argv, envp);
	return (0);
}
