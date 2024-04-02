#include "../include/minishell.h"

int	update_env_part3(t_mini *mini, char *part, char *_new)
{
	int			len;
	t_environ	*head;

	head = mini->env_test;
	len = ft_strlen(mini->env_test->env_var);
	while (mini->env_test && mini->env_test->env_var
		&& ft_strncmp(mini->env_test->env_var, part, len))
	{
		len = ft_strlen(mini->env_test->env_var);
		mini->env_test = mini->env_test->next;
	}
	if (mini->env_test && mini->env_test->env_val != NULL)
	{
		free(mini->env_test->env_val);
		mini->env_test->env_val = ft_strdup(_new);
	}
	mini->env_test = head;
	return (1);
}

char	*get_env_part(t_mini *mini, char *part)
{
	t_environ	*head;
	int			part_len;

	if (!part || !part[0])
		return (NULL);
	head = mini->env_test;
	while (head != NULL)
	{
		part_len = ft_strlen(mini->env_test->env_var);
		if (!ft_strncmp(head->env_var, part, part_len))
			return (head->env_val);
		head = head->next;
	}
	return (NULL);
}
