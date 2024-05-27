/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:07 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:08 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parsing_fail(int parsing, t_mini *mini)
{
	if (parsing == -1)
		ft_putendl_fd("exit", 2);
	free_minishell(mini);
	return (g_errno);
}

void	set_mini_no_wrds(void)
{
	t_mini	*mini;
	int		no_wrds;

	no_wrds = 0;
	mini = get_data();
	while (mini->cmds[no_wrds])
		no_wrds++;
	mini->no_wrds = no_wrds;
}

char	**parse_mini_cmds(void)
{
	int		cmd_index;
	int		cmd_nb;
	char	**new_cmds;
	t_mini	*mini;

	mini = get_data();
	set_mini_no_wrds();
	new_cmds = ft_calloc(mini->no_wrds + 1, sizeof(char *));
	if (!new_cmds)
		return (NULL);
	cmd_nb = 0;
	cmd_index = -1;
	while (mini->cmds[++cmd_index])
	{
		if (contain_cash(mini->cmds[cmd_index]) != 0
			|| (mini->cmds[cmd_index][0] == '$' && mini->cmds[cmd_index][1]
			&& mini->cmds[cmd_index][1] != '$'))
			new_cmds[cmd_nb] = (ft_dollar_switch(mini->cmds[cmd_index]));
		else
			new_cmds[cmd_nb] = ft_strdup(mini->cmds[cmd_index]);
		cmd_nb++;
	}
	return (new_cmds);
}
