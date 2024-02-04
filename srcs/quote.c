#include "../include/minishell.h"

bool    contain_quote(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '\"' || str[i] == '\'')
            return (1);
        i++;
    }
    return (0);
}

bool    contain_cash(char *str)
{
    int i;

    i = 0;
    while (str[i] & str[i] != '\0')
    {
        if (str[i] == '$')
            return (1);
        i++;
    }
    return (0);
}