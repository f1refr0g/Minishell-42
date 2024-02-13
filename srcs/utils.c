#include "../include/minishell.h"

int ft_isonlyspace(char *prompt)
{
    int i;

    i = 0;
    while (prompt[i] != '\0')
    {
        if (prompt[i] != 32)
            return (0);
        i++;
    }
    return (1);
}