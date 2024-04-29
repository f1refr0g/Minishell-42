#include "../include/minishell.h"

t_environ	*new_env(char *var)
{
	t_mini		*mini;
	t_environ	*new_env;

	mini = get_data();
	new_env = init_item(var);
	mini->env_len++;
	new_env->next = NULL;
	return (new_env);
}

//Exit minishell and call the janitor
void	ft_exit(t_data *data)
{
	if (check_exit(data->prompt) == 1)
	{
		ft_clean(data);
		exit (0);
	}
}

//FONCTION POUR TEST BUILTIN EXIT(REMOVE WHEN EXEC IS DONE)
int	check_exit(char *prompt)
{
	char	*exit;

	exit = "exit";
	if (ft_strlen(prompt) == ft_strlen(exit))
		if (ft_strncmp(prompt, exit, 4) == 0)
			return (1);
	return (0);
}
