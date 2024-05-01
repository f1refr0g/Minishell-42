#include "../include/minishell.h"

int	check_cd(char *prompt)
{
	char	*cd;

	cd = "cd";
	if (ft_strlen(prompt) == ft_strlen(cd))
		if (ft_strncmp(prompt, cd, 2) == 0)
			return (1);
	return (0);
}

//Exit minishell and call the janitor
void	ft_exit(t_data *data)
{
	if (check_exit(data->prompt) == 1)
	{
		ft_clean(data);
		exit (0);
	}
}

//FONCTION POUR TEST BUILTIN EXIT(REMOVE WHEN EXEC IS DONE)
int	check_exit(char *prompt)
{
	char	*exit;

	exit = "exit";
	if (ft_strlen(prompt) == ft_strlen(exit))
		if (ft_strncmp(prompt, exit, 4) == 0)
			return (1);
	return (0);
}
