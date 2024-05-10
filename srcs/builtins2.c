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

int	has_equal_sign(char **var)
{
	int	var_wrd;
	int	var_char;

	var_wrd = 0;
	var_char = 0;
	if (!var)
		return (0);
	if (!(var[0][0] == 0) && !ft_isalpha(var[0][0]))
		return (0);
	while (var[var_wrd])
	{
		var_char = 0;
		while (var[var_wrd][var_char])
		{
			if (var[var_wrd][var_char] == '=')
				return (1);
			var_char++;
		}
		var_wrd++;
	}
	return (0);
}

t_environ	*new_env(char *var)
{
	t_mini		*mini;
	t_environ	*new_env;

	mini = get_data();
	new_env = init_item(var);
	mini->env_len++;
	new_env->next = NULL;
	return (new_env);
}
