/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:40:15 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:40:16 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" 

int	check_file_exists(t_token *token)
{
	if (token->cmd && token->cmd[1] && ft_strncmp(token->cmd[0], "echo", 5))
	{
		if (token->cmd[1][0] != '-')
		{
			if (access(token->cmd[1], F_OK | X_OK) == 0)
				g_errno = 0;
			else
				g_errno = 1;
		}
	}
	return (g_errno);
}

void	tokens_next_sep(t_token *tokens)
{
	if (!ft_strncmp(tokens->next_sep, "|", 2))
		tokens->type = PIPE;
	else if (!ft_strncmp(tokens->next_sep, "<<", 3))
		tokens->type = REDIR_DBL2;
	else if (!ft_strncmp(tokens->next_sep, ">>", 3))
		tokens->type = REDIR_DBL;
	else if (!ft_strncmp(tokens->next_sep, "<", 2))
		tokens->type = REDIR_OUT;
	else if (!ft_strncmp(tokens->next_sep, ">", 2))
		tokens->type = REDIR_IN;
}

void	set_var_tokens(t_mini *mini, t_token *tokens, int x, int wrd_no)
{
	tokens->cmd[wrd_no] = NULL;
	tokens->type = 0;
	tokens->token_no = x;
	mini->no_of_tokens = x;
	tokens->env = mini->env_test;
	tokens->fd_out = 0;
	tokens->fd_in = 0;
	tokens->mini = mini;
	tokens->next = NULL;
	tokens->pid = 0;
}

int	ft_parse(t_mini	*mini)
{
	if (!check_valid_quotes(mini->input))
	{
		ft_putendl_fd("Invalid Input", 2);
		return (0);
	}
	mini->no_wrds = nb_of_words(mini->input, 0, 0, 0) + 1;
	mini->cmds = small_split(mini->input);
	if (!mini->cmds || mini->cmds == NULL)
		return (0);
	mini->new_cmds = parse_mini_cmds();
	if (!check_input(mini))
		return (0);
	releaser(mini->cmds);
	if (!tokeniser(mini))
		return (0);
	releaser(mini->new_cmds);
	if (!strncmp(mini->tokens->cmd[0], "exit", 5))
		return (ft_exit(mini->tokens->cmd));
	return (1);
}
