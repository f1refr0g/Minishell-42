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

void  ft_cd(t_data *data)
{
		char	**path;

		path = ft_split(data->prompt, 32);

		if (check_cd(data->prompt) == 1)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			if (chdir(path[1]) != 0)
			{
				printf("ERROR DE PATH\n");
			}
		}
		ft_free_array(path);
}

int  check_cd(char *prompt)
{
	char  *cd;
	
	cd = "cd";
	if (ft_strlen(prompt) == ft_strlen(cd))
		if (ft_strncmp(prompt, cd, 2) == 0)
			return (1);
		return (0);
}