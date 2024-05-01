#include "../include/minishell.h"

#include <stdlib.h>		// Free
#include <stdbool.h>	// Bool (true/false)

void	*releaser(char **table)
{
	int	i;

	i = 0;
	if (table)
	{
		while (table[i])
		{
			free(table[i]);
			i++;
		}
		free(table);
	}
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	t_data			data;
	static t_mini	*mini;
	int				parsing;

	(void)av;
	if (ac > 1 || !env[0])
		return (launch_fail(env));
	mini = get_data();
	ft_init_minishell(&data, env);
	while (1)
	{
		ft_signal_handler_parent(INTERACTIVE);
		mini->input = get_prompt("Minishell > ");
		if (!is_empty(mini->input))
		{
			parsing = ft_parse(mini);
			if (parsing < 0)
				return (parsing_fail(parsing, mini));
			else if (parsing > 0)
				run_minishell(mini);
		}
	}
	return (g_errno);
}
