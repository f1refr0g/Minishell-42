/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:35:01 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:35:03 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_real_env(char **env)
{
	int	x;

	x = -1;
	while (env[++x])
		ft_putendl_fd(env[x], 1);
}

void	print_env(t_environ *environ)
{
	t_environ	*head;

	head = environ;
	while (head)
	{
		ft_putstr_fd(head->env_var, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(head->env_val, 1);
		head = head->next;
	}
}

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

void	set_env(t_mini *mini, char **env)
{
	t_environ	*head;
	int			x;

	x = 0;
	mini->env_test = init_item(env[x]);
	head = mini->env_test;
	while (env[++x])
	{
		mini->env_test->next = init_item(env[x]);
		mini->env_test = mini->env_test->next;
	}
	mini->env_test = head;
}
