/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:34:40 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:34:43 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	do_export(t_mini *mini, char **var)
{
	int			x;
	char		*temp;
	t_environ	*head_new;
	t_export	*head;

	x = 0;
	head = mini->_export;
	while (head != NULL)
	{
		temp = get_env_part(mini, head->env_var);
		if (temp == NULL || temp[0] != '\0')
		{
			update_env_part3(mini, head->env_var, head->env_val);
			x++;
		}
		else
		{
			head_new = new_env(var[x++]);
			ft_envadd_back(&mini->env_test, head_new);
		}
		head = head->next;
	}
	free_export(mini->_export);
}
