#include "../include/minishell.h"

void	ft_cd(t_data *data, char **cmdarray)
{
	char    *oldpwd;
    char    *pwd;
    char    *newpwd;

    oldpwd = getcwd(NULL, PATH_MAX);

    if (!cmdarray[1])
        cmdarray[1] = get_env_line("HOME", data);

    if (!oldpwd)
    {
        printf("Error message\n");
        return ;
    }
    if (chdir(cmdarray[1]) == 0)
    {
        ft_unset(data,"OLDPWD");
        pwd = get_env_line("PWD", data);
        
        ft_export(data, cmdarray);

    }
}


//Return the value of a variable in a environment (use for cd)
//Think it is causing some minorleaks
char    *get_env_line(char *var, t_data *data)
{
    int i;

    i = 0;
    while (data->env[i++]) 
    {
        if (ft_strncmp(data->env[i], var, ft_strlen(var)) == 0)
        {
            if (data->env[i][ft_strlen(var)] == '=')
            {
                return (data->env[i] + ft_strlen(var) + 1);
            }
        }
       i++; 
    }
    return (NULL);

}
