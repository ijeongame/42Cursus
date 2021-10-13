/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:16:49 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/12 18:49:14 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** NONE 0
** CMD 1
** REDIRECT 2
** PIPE 4
** ARG 8
** S_QUOTE 16
** D_QUOTE 32

** RD_IN 1
** RD_OUT 2
** RD_APPEND 4
** RD_HEREDOC	8
** COMMAND 16
** ARGUMENT 32
*/

// static int	run_shell(t_mini *shell)
// {
// 	int i;

// 	i = -1;
// 	// 이부분을 t_LIST형태로 반복해야됨
// 	while (shell->cmd)
// 	{
// 		printf("token list argument check after parsing : %s\n", shell->cmd->arg);
// 		printf("token list type check after parsing : %d\n", shell->cmd->type);
// 		shell->cmd = shell->cmd->next;
// 		// if (shell->cmd->cmd == NULL)
// 		// 	shell->cmd->cmd = " ";
// 		// if (shell->pipe_flag == 0)
// 		// 	while (++i < BLTIN_NUM)
// 		// 		run_blt(shell, i);
// 		// else if (shell->re_flag == 1)
// 		// 	re_process(shell);
// 		// else
// 		// 	pipe_process(shell);
// 		// shell = shell->next;
// 	}
// 	return 1;
// }

void	minishell(char **en)
{
	int		status;
	char	*line;
	int		ret;
	t_mini	shell;

	status = 1;
	while (status)
	{
		//터미널을 종료시키는 인터럽트를 발생시켰을 때, 터미널이 종료되는게 아니라 우리의 minishell 프로그램만 종료되도록 액션을 변경해줘야 한다. 이런 핸들러 역할을 하는게 아래의 signal 함수이다.
		// show_prompt();
		// run_term(shell->term);
		//history && read_line->getch()
		tcsetattr(STDIN_FILENO, TCSANOW, &g_mini.term_ori);
		line = readline("input> ");
		if (line == NULL)
		{
			printf("exit\n");
			free(line);
			exit(0);
		}
		else if (ft_strchr("\n", *line))
			continue ;
		else
		{
			// printf("output> %s\n", line);
			shell.cmd = parse_start(line);
			add_history(line);
			free(line);
			line = NULL;
		}
		// debug
		shell.cmd = parse_start(line);
		while (shell.cmd)
		{
			while(shell.cmd->token)
			{
				printf("parsing cmd check after return : %s\n", shell.cmd->token->arg);
				printf("parsing cmd check after return : %d\n", shell.cmd->token->type);
				shell.cmd->token = shell.cmd->token->next;
			}
			shell.cmd = shell.cmd->next;
		}
		// end
		// status = run_shell(shell->cmd, &en);
	}
	(void)en;
}

//keycode 값을 받아와서
//getch() -> 따로 만들어줘야한다.
//parsing -> token화 시키기
//예외처리는 큰 것부터 하고 builtin부터 동작하게 만들기