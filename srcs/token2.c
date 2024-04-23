#include "../include/minishell.h"

int	tokeniser(t_mini *mini)
{
	int				x;
	t_token			*head;
	int				cmd_index;

	x = 0;
	cmd_index = 0;
	mini->tokens = init_tokens(mini, cmd_index, x);
	head = mini->tokens;
}
