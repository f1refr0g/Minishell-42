#include "../include/minishell.h"

int	pipe_check(char **cmds)
{
	int	cmd_no;
	int	trig;

	cmd_no = 0;
	trig = 0;
	if (cmds == NULL)
		return (0);
	while (cmds[cmd_no] && trig <= 1)
	{
		if (!ft_strncmp(cmds[cmd_no], "|", 2))
			trig++;
		else
			trig = 0;
		cmd_no++;
	}
	if (trig > 1)
		return (0);
	else
		return (1);
}

int	check_input(t_mini *mini)
{
	int	x;

	x = 0;
	if (pipe_check(mini->new_cmds) == 1 && redir_check(mini->new_cmds) == 1
		&& redir_check2(mini->new_cmds) == 1
		&& redir_check3(mini->new_cmds) == 1)
	{
		while (mini->new_cmds[x])
		{
			if ()
		}
	}
}