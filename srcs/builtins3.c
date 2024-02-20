#include "../include/minishell.h"

void    ft_unset(t_data *data, char *cmd)
{
    int i;
    int y;
    char *temp;

    i = -1;
    y = 0;
    temp = ft_substr(cmd, 0, ft_strchr(cmd, '=') - cmd);
    while (data->env[++i])
    {
        if (ft_strncmp(temp, data->env[i], ft_strlen(temp)) == 0)
        {
            free(data->env[i]);
            while (data->env[i + 1])
            {
                data->env[i] = data->env[i + 1];
                i++;
            }
            data->env[i] = NULL;
        }
    }
}

int     verify_double(t_data *data, char *cmd)
{
    int i;

    i = 0;
    while (data->env[i] != NULL)
    {
        if (ft_strncmp(cmd, data->env[i], ft_strlen(cmd)) == 0)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void    ft_export(t_data *data, char **cmd)
{
    int     i;
    char    *str;

    i = 0;

    if (ft_strncmp(cmd[0], "export", 6) == 0)
    {
        if (ft_strchr(cmd[1], '='))
        {
            str = ft_substr(cmd[1], 0, ft_strchr(cmd[1], '=') - cmd[1]);
            if (verify_double(data, str) == 1)
                ft_unset(data, cmd[1]);
            while(data->env[i])
                i++;
            data->env[i] = ft_strdup(cmd[1]);
            free(str);
        }
    }
}

void    ft_echo(char **cmd)
{
    if (ft_strncmp(cmd[0], "echo", 3) == 0)
    {
        if (ft_strncmp(cmd[1], "-n", 2) == 0)
            ft_printf("%s", cmd[2]);
        else
            ft_printf("%s\n", cmd[1]);
    }
}