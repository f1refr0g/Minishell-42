/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:34:23 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:34:26 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_export	*ft_exp(t_mini *mini, char *var)
{
	t_export	*export;

	(void)mini;
	export = malloc(sizeof(t_export));
	if (!export)
		return (NULL);
	export->temp = ft_split(var, '=');
	export->env_var = ft_strdup(export->temp[0]);
	if (var[ft_strlen(export->env_var)])
		export->env_val = ft_strdup(&var[ft_strlen(export->env_var) + 1]);
	else
		export->env_val = ft_strdup(" \0");
	export->next = NULL;
	releaser(export->temp);
	return (export);
}

void	init_export(t_mini *mini, char **var)
{
	t_export	*export_head;
	int			x;

	x = 0;
	mini->_export = ft_exp(mini, var[x]);
	export_head = mini->_export;
	while (var[++x])
	{
		mini->_export->next = ft_exp(mini, var[x]);
		mini->_export = mini->_export->next;
	}
	mini->_export->next = NULL;
	mini->_export = export_head;
}

int	check_export(char **var)
{
	int	x;
	int	ret;

	x = 0;
	ret = 1;
	if (!var || !var[0])
		return (0);
	while (var[x])
	{
		if ((var[x][0] == 0) || !ft_isalpha(var[x][0]))
		{
			ft_putstr_fd("export: ", 2);
			ft_putstr_fd(var[x], 2);
			ft_putstr_fd(" identifier not valid\n", 2);
			ret = 0;
		}
		x++;
	}
	return (ret);
}

int	export_no_input(t_mini *mini)
{
	t_environ	*head;

	head = mini->env_test;
	while (head)
	{
		ft_putstr_fd("declare -x", 1);
		ft_putstr_fd(head->env_var, 1);
		ft_putstr_fd("=", 1);
		ft_putchar_fd(34, 1);
		ft_putstr_fd(head->env_val, 1);
		ft_putchar_fd(34, 1);
		ft_putstr_fd("\n", 1);
		head = head->next;
	}
	return (0);
}
