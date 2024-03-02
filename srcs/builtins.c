#include "../include/minishell.h"

//Display the environment
void	ft_env(t_data *data)
{
	int	i;

	i = 0;
	if (check_env(data->prompt) == 1)
	{
		while (data->env[i] != NULL)
		{
			printf("%s\n", data->env[i]);
			i++;
		}
	}
}

//TEST FUNCTION FOR ENV EXEC(REMOVE WHEN EXEC IS DONE)
int	check_env(char *prompt)
{
	char	*env;

	env = "env";
	if (ft_strlen(prompt) == ft_strlen(env))
		if (ft_strncmp(prompt, env, 3) == 0)
			return (1);
	return (0);
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
