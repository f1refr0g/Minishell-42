/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:23 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/13 17:17:47 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**build_cmd(t_token *token)
{
	char	**s_cmd;
	char	**temp;
	int		cmd_no;

	cmd_no = 0;
	temp = ft_split(token->cmd[0], '/');
	if (!temp[0])
	{
		releaser(temp);
		return (NULL);
	}
	while (temp[cmd_no])
		cmd_no++;
	s_cmd = ft_calloc(3, sizeof(char *));
	if (!s_cmd)
		return (NULL);
	s_cmd[0] = ft_strdup(temp[cmd_no - 1]);
	if (token->cmd[1])
		s_cmd[1] = ft_strdup(token->cmd[1]);
	releaser(temp);
	return (s_cmd);
}

void	exec_abs_path(char *path, t_token *token)
{
	char	**s_cmd;
	char	**env;
	t_mini	*mini;

	s_cmd = build_cmd(token);
	if (s_cmd == NULL)
		return ;
	mini = get_data();
	if (access(path, F_OK | X_OK) == 0)
	{
		env = env_l_to_dbl_arr(mini->env_test);
		if ((path == NULL) || execve(path, s_cmd, env) < 0)
		{
			is_a_directory(token->cmd[0]);
			releaser(env);
			releaser(s_cmd);
		}
	}
	else
	{
		invalid_path(token->cmd[0]);
		releaser(s_cmd);
	}
}

void	abs_error(t_token *token)
{
	int	i;

	i = 2;
	if ((token->cmd[0][0] == '.' || token->cmd[0][0] == '/'))
	{
		if (!token->cmd[0][1])
		{
			is_a_directory(token->cmd[0]);
		}
		else if (token->cmd[0][2] && token->cmd[0][2] == '/')
		{
			while (token->cmd[0][i] == '/')
				i++;
			if (!token->cmd[0][i])
			{
				is_a_directory(token->cmd[0]);
			}
		}
	}
}

void	absolute_path(t_token *token)
{
	char	*path;
	char	*path2;
	char	*temp;

	abs_error(token);
	if (token->cmd[0][0] == '.')
	{
		path = malloc(100);
		if (!path || !token->cmd[0])
			return ;
		getcwd(path, 100);
		temp = ft_strjoin(path, "/");
		path2 = ft_strjoin(temp, token->cmd[0]);
		free(temp);
		free(path);
	}
	else
	{
		path2 = ft_strdup(token->cmd[0]);
	}
	exec_abs_path(path2, token);
	free(path2);
}
