/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:40:31 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:40:32 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_char_sep(int c)
{
	if ((c == '|' || c == '>' || c == '<'))
		return (1);
	return (0);
}

int	has_pipe(t_mini *mini)
{
	t_token	*head;

	head = mini->tokens;
	while (head->next != NULL)
	{
		if (head->type == PIPE)
			return (1);
		head = head->next;
	}
	return (0);
}

void	*ft_other_free(void *p)
{
	if (p)
		free(p);
	return (0x0);
}
