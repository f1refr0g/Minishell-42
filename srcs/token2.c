#include "../include/minishell.h"

t_token	*init_tokens(t_mini *mini, int cmd_index, int x)
{
	t_token	*tokens;
	int		wrd_no;

	wrd_no = 0;
	tokens = malloc(sizeof(t_token));
	tokens->cmd = malloc(sizeof(char *) * 100);
	if (mini->new_cmds[cmd_index] && is_sep(mini->new_cmds[cmd_index]))
		tokens->cmd[wrd_no++] = ft_strdup(mini->new_cmds[cmd_index++]);
	while (!is_sep(mini->new_cmds[cmd_index]) && mini->new_cmds[cmd_index])
	{
		if (!has_quotes(mini->new_cmds[cmd_index]))
			tokens->cmd[wrd_no] = ft_strdup(mini->new_cmds[cmd_index]);
		else
			tokens->cmd[wrd_no] = ft_strdup2(mini->new_cmds[cmd_index]);
		wrd_no++;
		cmd_index++;
	}
	set_var_tokens(mini, tokens, x, wrd_no);
	return (tokens);
}

void	ft_chain(t_mini *mini, int cmd_index)
{
	int		x;
	t_token	*head;

	x = 1;
	head = mini->tokens;
	if (is_sep(mini->new_cmds[cmd_index]))
		cmd_index++;
	while (cmd_index < mini->no_wrds || mini->new_cmds[cmd_index] != NULL)
	{
		if (is_sep(mini->new_cmds[cmd_index]) && mini->new_cmds[cmd_index + 1]
			&& cmd_index)
			cmd_index++;
		mini->tokens->next = init_tokens(mini, cmd_index, x++);
		mini->tokens = mini->tokens->next;
	}
}

void	token_type(t_token *tokens)
{
	if (tokens->next_sep)
		tokens_next_sep(tokens);
	else
		tokens->type = 1;
	if (!ft_strncmp(tokens->cmd[0], "<", 2))
		tokens->type = REDIR_OUT;
	if (!ft_strncmp(tokens->cmd[0], ">", 2))
		tokens->type = REDIR_IN;
	else if (tokens->cmd && (tokens->cmd[0][0] == '.'
		|| tokens->cmd[0][0] == '/'))
		tokens->type = ABS;
}

int	get_types(t_mini *mini)
{
	t_token	*head;

	head = mini->tokens;
	while (mini->tokens != NULL)
	{
		if (mini->tokens->type >= 0)
			token_type(mini->tokens);
		mini->tokens = mini->tokens->next;
	}
	mini->tokens = head;
	return (1);
}

int	tokeniser(t_mini *mini)
{
	int				x;
	t_token			*head;
	int				cmd_index;

	x = 0;
	cmd_index = 0;
	mini->tokens = init_tokens(mini, cmd_index, x);
	head = mini->tokens;
	while (mini->new_cmds[cmd_index] && !is_sep(mini->new_cmds[cmd_index]))
		cmd_index++;
	if (mini->new_cmds[cmd_index] && is_sep(mini->new_cmds[cmd_index]))
		mini->tokens->next_sep = ft_strdup(mini->new_cmds[cmd_index]);
	else
		mini->tokens->next_sep = NULL;
	ft_chain(mini, cmd_index);
	mini->tokens = head;
	if (!get_types(mini))
		return (0);
	return (1);
}
