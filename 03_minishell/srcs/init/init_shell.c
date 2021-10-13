/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:45:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/10/12 18:52:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt(void)
{
	char	buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	write(1, buf, ft_strlen(buf));
	write(1, " > ", 3);
}

void	init_env(char ***en, char *envp[])
{
	int	i;
	int	j;

	i = -1;
	while (envp[++i])
		NULL;
	(*en) = (char **)ft_malloc(sizeof(char *) * i);
	i = -1;
	while (envp[++i])
	{
		(*en)[i] = (char *)ft_malloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*en)[i][j] = envp[i][j];
		(*en)[i][j] = 0;
	}
	(*en)[i] = NULL;
	return ;
}

// terminal setting
void	init_term(void)
{
	tcgetattr(STDIN_FILENO, &g_mini.term_ori);
	tcgetattr(STDIN_FILENO, &g_mini.term_sh);
	g_mini.term_sh.c_lflag &= ~(ICANON | ECHO);
	g_mini.term_sh.c_lflag |= VEOF;
	g_mini.term_sh.c_cc[VMIN] = 1;
	g_mini.term_sh.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_mini.term_sh);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_mini.term_ori);
}

void	signal_int(int sig_num)
{
	// if (g_mini.pid > 0)
	// {
	// 	!kill(g_global.pid, signo)
	// 	ft_putstr_fd("\n", STDOUT_FILENO);
	// }
	if (sig_num != SIGINT)
		return ;
	ft_putstr_fd("\n", STDOUT);
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	signal_quit(int sig_num)
{
	g_mini.sig_flag = sig_num;
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	init_shell(char ***en, char *envp[])
{
	init_env(en, envp);
	init_term();
	signal(SIGINT, signal_int); //ctrl + c
	signal(SIGQUIT, signal_quit); //ctrl + '\'
}
