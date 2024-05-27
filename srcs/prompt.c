/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:22 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:23 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_prompt(char *ptr)
{
	char	*line;
	t_mini	*mini;

	mini = get_data();
	line = readline(ptr);
	while (line)
	{
		if (!is_empty(line))
			add_history(line);
		return (line);
	}
	ft_putendl_fd("exit", 2);
	if (mini)
	{
		free_env(mini->env_test);
		free(mini);
	}
	exit(g_errno);
	return (NULL);
}

char	*get_hd_prompt(char *prt)
{
	char	*line;
	t_mini	*mini;

	mini = get_data();
	line = readline(prt);
	while (line)
	{
		if (!is_empty(line))
			add_history(line);
		return (line);
	}
	g_errno = 1;
	if (mini->tokens->fd_hd)
		close(mini->tokens->fd_hd);
	free_minishell(mini);
	exit(g_errno);
	return (NULL);
}
