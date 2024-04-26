#include "../include/minishell.h"

//Display the current path
int	ft_pwd(t_token *token)
{
	char	pwd[100];

	getcwd(pwd, 100);
	free(token->cmd[0]);
	token->cmd[0] = ft_strdup(pwd);
	ft_putendl_fd(pwd, 1);
	return (1);
}

//TEST FUNCTION TO SEE IF PWD WORK (REMOVE WHEN EXECUTION IS DONE)
int	check_pwd(char *prompt)
{
	char	*pwd;

	pwd = "pwd";
	if (ft_strlen(prompt) == ft_strlen(pwd))
		if (ft_strncmp(prompt, pwd, 3) == 0)
			return (1);
		return (0);
}

int	check_cd(char *prompt)
{
	char	*cd;

	cd = "cd";
	if (ft_strlen(prompt) == ft_strlen(cd))
		if (ft_strncmp(prompt, cd, 2) == 0)
			return (1);
		return (0);
}
