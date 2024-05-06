
#include "../include/minishell.h"

void	continue_child(t_token *token)
{
	if (token->type == ABS)
		absolute_path(token);
	else if (!ft_strncmp(token->cmd[0], "echo", 5))
		ft_echo(token);
	else if (!ft_strncmp(token->cmd[0], "pwd", 4))
		ft_pwd(token);
}

void	do_child_stuff(t_token *token)
{
	t_mini	*mini;
	t_token	*temp;

	temp = token;
	mini = get_data();
	if (token->type == REDIR_IN || token->type == REDIR_DBL)
	{
		child_redir_to(token);
		exec(temp);
	}
	else if (token->type == REDIR_OUT)
		redir2(token);
	else if (token->type == HEREDOC_T)
		heredoc(token);
	else if (token->type == PIPE && !ft_strncmp(mini->tokens->cmd[0], "cat", 4))
		do_pipe_cat(token);
	else if (token->type == PIPE || (token->next && !ft_strncmp(token->next_sep,
				"|", 1)))
		do_pipe(token);
	else if (token->type == ABS || (!ft_strncmp(token->cmd[0], "echo", 5))
		|| (!ft_strncmp(token->cmd[0], "pwd", 4)))
		continue_child(token);
	else
		exec(token);
	exit(free_minishell(mini));
}

void	continue_exec(t_token *token)
{
	t_token	*temp;

	if (token->next && token->next->type == REDIR_OUT)
		exec_and_stuff(token->next);
	if (token->next && token->next->next && (token->type == REDIR_IN
			|| token->type == REDIR_DBL))
	{
		temp = token;
		while (token->type == REDIR_IN && token->next)
		{
			token = token->next;
		}
		if (token->next && ft_strncmp(token->next->cmd[0], "cat", 3) != 0
			&& ft_strncmp(token->next->cmd[0], "wc", 3) != 0)
			exec_and_stuff(token->next);
	}
}

void	exec_and_stuff(t_token	*token)
{
	pid_t	pid;
	t_mini	*mini;

	mini = get_data();
	update_error(mini);
	if (token == NULL)
		return ;
	if (!ft_builtins(token))
	{
		pid = fork();
		if (pid == 0)
			do_child_stuff(token);
		else
		{
			waitpid(pid, NULL, 0);
			if (token->token_no > 0)
				wait_pids(token);
		}
		continue_exec(token);
	}
}

void	exec_and_stuff2(t_token *token)
{
	t_token	*head;

	head = token;
	if (!ft_builtins(head))
	{
		if (head->token_no > 0)
			wait_pids(head);
		do_child_stuff(head);
	}
	if (head->next && head->next->type == REDIR_OUT)
		exec_and_stuff2(head->next);
	if (head->next && head->next->next && (head->type == REDIR_IN
			|| head->type == REDIR_DBL))
	{
		exec_and_stuff2(head->next->next);
	}
}

void	ft_execute(t_data *data)
{
	int		i;
	pid_t	pid;
	int		fd[2];
	int		prev_fd[2];

	i = 0;
	while (data->cmd_array[i] != NULL)
	{
		if (pipe(fd) == -1)
			printf("Erreur de pipe\n");
		pid = fork();
		if (pid == -1)
			printf("Erreur de fork\n");
		else if (pid == 0)
		{
			if (i >= 0)
			{
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
			}
			if (data->cmd_array[i + 1] != NULL)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			get_command(data->cmd_array[i], data->env, 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (i > 0)
			{
				close(prev_fd[0]);
				close(prev_fd[1]);
			}
			prev_fd[0] = fd[0];
			prev_fd[1] = fd[1];
			i++;
		}
	}
	close(prev_fd[0]);
	close(prev_fd[1]);
	while (wait(NULL) > 0);
}
