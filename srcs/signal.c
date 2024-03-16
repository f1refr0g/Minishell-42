#include "minishell.h"

void	regular_shell(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	else if (signal == SIGQUIT)
		write(STDERR_FILENO, "QUIT\n", 8);
}

void	interactive_shell(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal_handler_parent(bool mute, bool is_interactive)
{
	if (mute == true)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (is_interactive == true)
	{
		signal(SIGINT, interactive_shell);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, regular_shell);
		signal(SIGQUIT, regular_shell);
	}
}
