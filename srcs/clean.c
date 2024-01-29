#include "../include/minishell.h"

void    ft_clean(t_data *data)
{
    if (data->env != NULL)
    {
        ft_free_array(data->env);
    }
}