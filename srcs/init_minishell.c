#include "../include/minishell.h"

//Init env, then init minishell
void	ft_set_env(t_mini *mini, char **env)
{
	t_environ	*head;
	int			x;

	x = 0;
	mini->env_test = init_item(env[x]);
	head = mini->env_test;
	while (env[++x])
	{
		mini->env_test->next = init_item(env[x]);
		mini->env_test = mini->env_test->next;
	}
	mini->env_test = head;
}

void	ft_init_minishell(t_data *data, char **env)
{
	t_mini	*mini;

	mini = get_data();
	mini->env = env;
	mini->cmds = NULL;
	mini->new_cmds = NULL;
	g_errno = 0;
	ft_set_env(mini, env);
	set_shlvl();
	update_env_part3(mini, "OLDPWD", "/");
	ft_init_env(data, env);
	data->state = 0;
}

//Initialize environment
void	ft_init_env(t_data *data, char **env)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	data->env = malloc((count + 1) * (sizeof(char *)));
	if (!data->env)
		return (ft_error(MALLOC_ERROR));
	ft_memset(data->env, 0, (count + 1) * sizeof(char *));
	while (env[i] != NULL)
	{
		data->env[i] = ft_calloc(ft_strlen(env[i]) + 1, sizeof(char));
		ft_memcpy(data->env[i], env[i], ft_strlen((env[i])) + 1);
		i++;
	}
}
