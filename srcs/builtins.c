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

void    ft_exit(t_data *data)
{
    if (check_exit(data->prompt) == 1)
    {
        ft_clean(data);
        exit (0);
    }
}

int     check_exit(char *prompt)
{
    int i;
    int y;
    char *exit;

    i = 0;
    y = 0;
    exit = "exit";

    while (prompt[i] != '\0')
    {
        y = 0;
        if (prompt[i] == exit[y])
        {
            while (exit[y] != '\0')
            {
                if (prompt[i] != exit[y])
                    break;
                i++;
                y++;
            }
            return (1);
        }
        i++;
    }
    return (0);
}