#include "../include/minishell.h"

//Fixer le probleme de cd seul, 
void	ft_cd(t_data *data, char **cmdarray)
{
	char    *oldpwd;
    char    *pwd;
    char    *newpwd;

    if(check_cd(cmdarray[0]) == 1)
    {
    if (!cmdarray[1])
    {
        newpwd = get_env_line("HOME", data);
        ft_cd_home(data, cmdarray, newpwd);
    }
    if (cmdarray[1] && chdir(cmdarray[1]) == 0)
    {
        ft_unset(data,"OLDPWD");
        pwd = get_env_line("PWD", data);
        oldpwd = ft_strjoin("OLDPWD=", pwd);
        ft_cd_export(data, cmdarray, oldpwd);
        free(oldpwd);
        ft_unset(data, "PWD");
        oldpwd = getcwd(NULL, 0);
        newpwd = ft_strjoin("PWD=", oldpwd);
        ft_cd_export(data, cmdarray, newpwd);
        free(newpwd);
        free(oldpwd);
    }
    else
        write(2, "Error cd : Directory not found\n", 31);
    }
}

void    ft_cd_home(t_data *data, char **cmdarray, char *home)
{
        char *oldpwd;
        char *pwd;
        char *newpwd;

        if (home == NULL)
            write(2, "Home is not set\n", 16);

        printf("home = %s\n", home);

        ft_unset(data,"OLDPWD");
        pwd = get_env_line("PWD", data);
        oldpwd = ft_strjoin("OLDPWD=", pwd);
        ft_cd_export(data, cmdarray, oldpwd);
        free(oldpwd);
        ft_unset(data, "PWD");
        oldpwd = getcwd(NULL, 0);
        newpwd = ft_strjoin("PWD=", home);
        ft_cd_export(data, cmdarray, newpwd);
        free(newpwd);
        free(oldpwd);
}

//Return the value of a variable in a environment (use for cd)
//Think it is causing segfault when the variable dont exist
char    *get_env_line(char *var, t_data *data)
{
    int i;

    i = 0;
    while (data->env[i])
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
    write(2, "Minishell cd : HOME is not set\n", 31);
    return (NULL);

}

void	ft_cd_export(t_data *data, char **cmd, char *pwd)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strncmp(cmd[0], "cd", 2) == 0)
	{
		if (cmd[1])
		{
			str = ft_substr(pwd, 0, ft_strchr(pwd , '=') - pwd);
			if (verify_double(data, str) == 1)
				ft_unset(data, pwd);
			while (data->env[i])
				i++;
			data->env[i] = ft_strdup(cmd[1]);
			free(str);
		}
	}
}