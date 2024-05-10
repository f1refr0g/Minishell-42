#include "../include/minishell.h"

void	ft_unset2(t_mini *mini)
{
	t_environ	*temp;

	if (mini->env_test->next != NULL)
	{
		free(mini->env_test->next->env_var);
		free(mini->env_test->next->env_val);
		releaser(mini->env_test->next->temp);
		if (mini->env_test->next->next)
		{
			temp = mini->env_test->next->next;
			free(mini->env_test->next);
			mini->env_test->next = temp;
		}
		else
		{
			free(mini->env_test->next);
			mini->env_test->next = NULL;
		}
	}
}

int	ft_unset(t_token *token)
{
	char		*part;
	int			cmd_no;
	int			len;
	t_environ	*head;
	t_mini		*mini;

	mini = get_data();
	if (!token->cmd[1] || !token->cmd[1][0])
		return (0);
	cmd_no = -1;
	while (token->cmd[cmd_no])
	{
		part = (token->cmd[cmd_no]);
		len = ft_strlen(part);
		head = mini->env_test;
		while (mini->env_test->next && ft_strncmp(part,
				mini->env_test->next->env_var, len) != 0)
			mini->env_test = mini->env_test->next;
		ft_unset2(mini);
		mini->env_test = head;
		mini->env_len--;
		cmd_no++;
	}
	return (0);
}

int	ft_export(t_mini *mini, char **var)
{
	if (!var || !var[0] || !var[0][0])
		return (export_no_input(mini));
	if (!check_export(var))
		return (0);
	init_export(mini, var);
	do_export(mini, var);
	return (0);
}

void	ft_echo2(int i, int n_option, t_token *token)
{
	while (token->cmd[i])
	{
		ft_putstr_fd(token->cmd[i], 1);
		if (token->cmd[i + 1] && token->cmd[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (n_option <= 0)
		write(1, "\n", 1);
}

int	ft_echo(t_token *token)
{
	int	i;
	int	j;
	int	n_option;

	i = 1;
	j = 1;
	n_option = -1;
	if (!token->cmd[1] || token->cmd[1] == NULL)
		return (write(1, "\n", 1));
	while (token->cmd[i] && !ft_strncmp(token->cmd[i], "-n", 2)
		&& n_option != 0)
	{
		n_option = 1;
		while (token->cmd[i][j] == 'n')
			j++;
		if (ft_isalnum(token->cmd[i][j]) || token->cmd[i][j] == '-')
		{
			i--;
			n_option = 0;
		}
		i++;
	}
	ft_echo2(i, n_option, token);
	return (1);
}
