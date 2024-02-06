#include "../include/minishell.h"

void    ft_pwd(t_data *data)
{
    char    pwd[PATH_MAX];

    if (check_pwd(data->prompt) == 1)
    {
      if (getcwd(pwd, PATH_MAX) != NULL)
        printf("%s\n", pwd);
      else
        printf("No path available\n");
    }
}

int     check_pwd(char *prompt)
{
    int i;
    int y;
    char *pwd;

    i = 0;
    y = 0;
    pwd = "pwd";

    while (prompt[i] != '\0')
    {
        y = 0;
        if (prompt[i] == pwd[y])
        {
            while (pwd[y] != '\0')
            {
                if (prompt[i] != pwd[y])
                    break;
                i++;
                y++;
            }
            if (pwd[y] == '\0')
                return (1);
        }
        i++;
    }
    return (0);
}