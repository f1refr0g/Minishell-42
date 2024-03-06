#include "minishell.h"

//Verifier pour les input du style cdexit etc
//faire un strlen du input et du comparateur && ft_strlen dans le dispatcheur comme condition
int	ft_dispatcher(char **tab)
{
	while (tab[0])
	{
		if (ft_strncmp(tab[0], "cd", 2 == 0))
			return (E_CD);
		if (ft_strncmp(tab[0], "unset", 5) == 0)
			return (E_UNSET);
		if (ft_strncmp(tab[0], "export", 6) == 0)
			return (E_EXPORT);
		if (ft_strncmp(tab[0], "pwd", 3) == 0)
			return (E_PWD);
		if (ft_strncmp(tab[0], "echo", 4) == 0)
			return (E_ECHO);
		if (ft_strncmp(tab[0], "env", 3) == 0)
			return (E_ENV);
		if (ft_strncmp(tab[0], "exit", 4) == 0)
			return (E_EXIT);
	}
	return (-1);
}

//Standardizer les inputs de chaque fonction et les outpout AJOUTER CD
int	ft_builtex(int flag, t_data *data)
{
	// if (flag == 0)
	// 	ft_cd();
	if (flag == 1)
		ft_unset(data, (cmd));
	if (flag == 2)
		ft_export(data, (cmd));
	if (flag == 3)
		ft_pwd(data);
	if (flag == 4)
		ft_echo(input valide);
	if (flag == 5)
		ft_env(data);
	if (flag == 6)
		ft_exit(data);
}
