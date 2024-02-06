#include "../include/minishell.h"

//Display the current path
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

//TEST FUNCTION TO SEE IF PWD WORK (REMOVE WHEN EXECUTION IS DONE)
int     check_pwd(char *prompt)
{
    char *pwd;

    pwd = "pwd";
    if (ft_strlen(prompt) == ft_strlen(pwd))
        if (ft_strncmp(prompt, pwd, 3) == 0)
            return (1);
    return (0);
}