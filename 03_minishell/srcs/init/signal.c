void	sig_handler(int signo)
{
	if (g_global.pid > 0)
	{
		if (!kill(g_global.pid, signo))
		{
			g_global.signal_on = 1;
			if (signo == SIGINT)
				ft_putstr_fd("\n", STDOUT_FILENO);
			else if (signo == SIGQUIT)
				ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		}
		else
		{
			if (signo == SIGINT)
			{
				ft_putstr_fd("\n", STDOUT_FILENO);
				g_global.signal_on = 1;
				g_global.exit = 1;
				prompt();
			}
		}
	}
}

void	*signal_ctlc(int signo)
{
	if (g_ex.pid == 0)
	{
		write(1, "\ngun_mandoo_shell > ", ft_strlen("\ngun_mandoo_shell > "));
		g_ex.is_signaled = 1;
	}
	else if (g_ex.pid > 0)
		write(1, "\n", 1);
	return (0);
	(void)signo;
}

void	*signal_ctlslash(int signo)
{
	if (g_ex.pid > 0)
		write(2, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	return (0);
	(void)signo;
}

void	set_handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void		handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			ft_putstr_fd("\b\b  \b\b\n", STDOUT);
			show_prompt();
			g_exit_status = 1;
		}
		else
			ft_putchar_fd('\n', STDOUT);
	}
	else if (signo == SIGQUIT)
	{
		if (pid == -1)
			ft_putstr_fd("\b\b  \b\b", STDOUT);
		else
			ft_putstr_fd("Quit: 3\n", STDOUT);
	}
}