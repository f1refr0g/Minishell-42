#include "../include/minishell.h" 

char    **ft_parse(t_data *data)
{
    int i;
    char    **tab;

    i = -1;
    tab = ft_split(data->prompt, 32);
    // while(tab[i++])
    //     printf("line %d - %s\n", i, tab[i]);

    return (tab);
}

void    ft_expend(t_data *data)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (data->prompt[i] != '\0')
    {
        if (data->prompt[i] == '|')
        {
            flag = i;

        }
    }
}

int     ft_count(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] && str[i] != '\0')
    {
        if (str[i] == '|')
            count += 2;
        while (ft_strncmp(&str[i], ">>", 2) == 0 ||
            ft_strncmp(&str[i], "<<", 2) == 0)
            {
                count += 2;
                i += 2;
            }
        if (str[i] == '>' || str[i] == '<')
            count += 2;
        if (str[i])
            i++;
    }
    return (count);
}

