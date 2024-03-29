#include "../include/minishell.h"

void	ft_int_handler(int signal)
{
	(void)signal;
	rl_on_new_line();
	kill(0, 0);
}

void	ft_quit_handler(int signal)
{
	(void)signal;
	kill(0, 0);
}

void	ft_doc_sig_handle(int signal)
{
	(void)signal;
	ft_putendl_fd("\0", 1);
	exit(1);
}

void	interactive_shell(int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signal;
}

void	ft_signal_handler_parent(int mode)
{
	if (mode == INTERACTIVE)
	{
		signal(SIGINT, &interactive_shell);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == CHILD)
	{
		signal(SIGINT, &ft_int_handler);
		signal(SIGQUIT, &ft_quit_handler);
	}
	else if (mode == HERE_DOC_SIG)
	{
		signal(SIGINT, &ft_doc_sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
}
