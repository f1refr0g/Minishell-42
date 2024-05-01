#include "../include/minishell.h"

//Janitor function that free any allocated memory
void	ft_clean(t_data *data)
{
	if (data->env != NULL)
	{
		ft_free_array(data->env);
	}
	if (data->array != NULL)
	{
		ft_free_array(data->array);
	}
}

//if minishell doesn't launch
int	launch_fail(char **env)
{
	if (!env[0])
		ft_putendl_fd("Unable to launch Minishell", 2);
	return (0);
}
