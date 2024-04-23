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
