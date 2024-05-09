#include "../include/minishell.h" 

char	***ft_commandarray(t_data *data)
{
	char	***cmd_array;
	char	**splited_pipe;
	int		count;
	int		i;

	count = 0;
	i = 0;
	splited_pipe = ft_splitdoc(data->prompt, '|');
	while (splited_pipe[count] != NULL)
		count++;
	cmd_array = malloc((count + 1) * sizeof(char **));
	if (cmd_array == NULL)
		printf(MALLOC_ERROR);
	while (i < count)
	{
		cmd_array[i] = ft_splitdoc(splited_pipe[i], 32);
		i++;
	}
	cmd_array[i] = NULL;
	return (cmd_array);
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
	if (mini->cmds || mini->cmds == NULL)
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

//Count the number of redirection (times 2) for ft_expend
int	ft_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == '|')
			count += 2;
		while (ft_strncmp(&str[i], ">>", 2) == 0
			|| ft_strncmp(&str[i], "<<", 2) == 0)
		{
			count += 2;
			i += 2;
		}
		if (str[i] == '>' || str[i] == '<')
			count += 2;
		if (str[i])
			i++;
	}
	return (count);
}
