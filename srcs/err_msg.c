#include "../include/minishell.h"

int	syntax_error(void)
{
	t_mini	*mini;

	mini = get_data();
	ft_putstr_fd("Minishell: ", 2);
	ft_putendl_fd("syntax error", 2);
	releaser(mini->cmds);
	releaser(mini->new_cmds);
	g_errno = 258;
	return (258);
}

int	invalid_path(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : No such file or directory", 2);
	return (0);
}

int	is_a_directory(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : command not found", 2);
	g_errno = 126;
	return (126);
}

int	command_not_found(char *error)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(" : command not found", 2);
	g_errno = 127;
	return (127);
}
