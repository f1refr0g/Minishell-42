#include "../include/minishell.h"

//Janitor function that free any allocated memory
void    ft_clean(t_data *data)
{
    if (data->env != NULL)
    {
        ft_free_array(data->env);
    }
    if (data->array != NULL)
    {
        ft_free_array(data->array);
    }
    if (data->expended != NULL)
        free(data->expended);
}