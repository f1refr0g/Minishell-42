#include "../include/minishell.h"

void    ft_env(t_data *data)
{
    int i = 0;
    while (data->env[i] != NULL)
    {
        printf("%s\n", data->env[i]);
        i++;
    }
}