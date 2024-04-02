#include "../include/minishell.h"

char	*get_prompt(char *ptr)
{
	char	*line;
	t_mini	*mini;

	mini = get_data();
	line = readline(ptr);
	while (line)
	{
		if (!is_empty(line))
			add_history(line);
		return (line);
	}
	ft_putendl_fd("exit", 2);
	if (mini)
	{
		free_env(mini->env_test);
		free(mini);
	}
	exit(g_errno);
	return (NULL);
}
