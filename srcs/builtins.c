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

void	exit_neg(int neg_errno)
{
	while (neg_errno < 0)
		neg_errno += 256;
	g_errno = neg_errno;
}

void	exit_num_errors(char **cmds)
{
	ft_putendl_fd("exit", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(cmds[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
}

void	exit_arg_errors(void)
{
	ft_putendl_fd("exit", 2);
	ft_putendl_fd("minishell: exit: too many arguments", 2);
}

//Exit minishell
int	ft_exit(char **cmds)
{
	int	neg_errno;

	if (cmds[1] && cmds[1][0])
	{
		if (cmds[1][0] == '-' && cmds[1][1])
		{
			neg_errno = ft_atoi(cmds[1]);
			exit_neg(neg_errno);
			return (-1);
		}
		if (!ft_isdigit(cmds[1][0]) || (cmds[1][0] == '-' && !cmds[1][1]))
		{
			exit_num_errors(cmds);
			g_errno = 255;
			return (-2);
		}
		if (cmds[2] && cmds[2][0])
		{
			exit_arg_errors();
			g_errno = 1;
			return (0);
		}
		g_errno = ft_atoi(cmds[1]);
	}
	return (-1);
}
