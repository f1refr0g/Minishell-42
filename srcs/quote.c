#include "../include/minishell.h"

bool    contain_quote(char *str, int len, int quote)
{
    bool    single_quote;
    bool    double_quote;
    int     i;

    single_quote = false;
    double_quote = false;
    i = 0;
    if (len == 0 || !str)
        return (false);
    while (i <= len)
    {
        if (str[i] == '\"' && !single_quote)
            double_quote = !double_quote;
        if (str[i] == '\'' && !double_quote)
            single_quote = !single_quote;
    i++;
    }
    if (quote == QUOTE && (single_quote || double_quote))
        return (true);
    else if (quote == SINGLE_QUOTE && single_quote)
        return (true);
    else if (quote == DOUBLE_QUOTE && double_quote)
        return (true);
    return (false);
}

bool    contain_cash(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '$')
            return (1);
        i++;
    }
    return (0);
}
