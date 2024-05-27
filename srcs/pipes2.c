/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:19 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:20 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	do_pipe2(t_token *token)
{
	pid_t	pid;

	if (pipe(token->p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		dup2_1(token);
		exec(token);
		free_minishell(token->mini);
		exit(0);
	}
	else
	{
		token->pid = pid;
		dup2_0(token);
		exec_and_stuff(token->next->next);
	}
}

void	child_do_pipe3(t_token *token)
{
	do_heredoc(token);
	free_minishell(token->mini);
	exit(0);
}

void	do_pipe3(t_token *token)
{
	pid_t	pid;

	if (pipe(token->p_fd) == -1)
		exit(0);
	pid = fork();
	if (!pid)
	{
		dup2_1(token);
		child_do_pipe3(token);
		exit(0);
	}
	else
	{
		dup2_0(token);
		waitpid(pid, NULL, 0);
		while (token->type != PIPE && token->next)
			token = token->next;
		exec_and_stuff(token->next);
	}
}
