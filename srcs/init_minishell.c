#include "../include/minishell.h"

//Init env, then init minishell
void    ft_init_minishell(t_data *data, char **env)
{
    ft_init_env(data, env);
}

//Initialize environment
void    ft_init_env(t_data *data, char **env)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (env[count])
        count++;
    
    data->env = malloc((count + 1) * (sizeof(char *)));
    if (!data->env)
        return(ft_error(MALLOC_ERROR));
    while(env[i] != NULL)
    {
        data->env[i] = ft_calloc(ft_strlen((env[i]) + 1), sizeof(char));
        ft_memcpy(data->env[i], env[i], ft_strlen((env[i]) + 1));
        i++;
    }
}