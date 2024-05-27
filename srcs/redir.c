/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:37 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:38 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	token_size(t_token *token)
{
	int	size;

	size = 0;
	while (token->cmd[size])
		size++;
	return (size);
}

void	redir(t_token *token)
{
	if (token->type == REDIR_IN)
		token->fd_out = open(token->next->cmd[0], O_WRONLY | O_CREAT | O_TRUNC,
				0777);
	else
		token->fd_out = open(token->next->cmd[0], O_WRONLY | O_CREAT | O_APPEND,
				0777);
	dup2(token->fd_out, 1);
	close(token->fd_out);
	if (token->next && (token->next->type == REDIR_IN
			|| token->next->type == REDIR_DBL))
		redir(token->next);
}
