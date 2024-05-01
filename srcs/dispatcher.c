
#include "../include/minishell.h"

int	is_builtin(t_token *token)
{
	if (!ft_strncmp(token->cmd[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "PWD", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "export", 6) && !token->cmd[1])
		return (1);
	else if (!ft_strncmp(token->cmd[0], "export", 6))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "unset", 5))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "env", 3))
		return (1);
	else if (!ft_strncmp(token->cmd[0], "cd", 2))
		return (1);
	else
		return (0);
}

int	ft_builtins(t_token *token)
{
	t_mini	*mini;

	mini = get_data();
	if (!ft_strncmp(token->cmd[0], "cd", 2))
		ft_cd(mini, token);
	else if (!ft_strncmp(token->cmd[0], "unset", 5))
		ft_unset(token);
	else if (!ft_strncmp(token->cmd[0], "export", 6) && !token->cmd[1])
		ft_export(mini, NULL);
	else if (!ft_strncmp(token->cmd[0], "export", 6))
		ft_export(mini, &token->cmd[1]);
	else if (!ft_strncmp(token->cmd[0], "env", 3))
		ft_env(token);
	else
		return (0);
	return (1);
}
