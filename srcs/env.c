#include "../include/minishell.h"

t_environ	*ft_envlast(t_environ *env)
{
	t_environ	*head;

	head = env;
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

void	ft_envadd_back(t_environ **env, t_environ *neo)
{
	t_environ	*temp;

	if (*env == NULL)
		*env = neo;
	else
	{
		temp = ft_envlast(*(env));
		temp->next = neo;
	}
}

t_environ	*init_item(char *to_split)
{
	t_environ	*env;

	env = malloc(sizeof(t_environ));
	if (!env)
		return (NULL);
	env->temp = ft_split(to_split, '=');
	if (!to_split || !env)
		return (NULL);
	if (env->temp && env->temp[0])
		env->env_var = ft_strdup(env->temp[0]);
	if (env->temp && env->temp[1])
		env->env_val = ft_strdup(&to_split[ft_strlen(env->env_var) + 1]);
	else
		env->env_val = ft_strdup(" \0");
	env->next = NULL;
	return (env);
}
