#include "../include/minishell.h"


char	*get_command_path(char *argv, char **envp)
{
	char	**path_list;
	char	*splitted_path;
	char	*pat;
	int		i;

	i = 0;
	if (!argv)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_list = ft_split(envp[i], ':');
	i = 0;
	while (path_list[i])
	{
		splitted_path = ft_strjoin(path_list[i++], "/");
		if (!splitted_path)
			return (NULL);
		pat = ft_strjoin(splitted_path, argv);
		free(splitted_path);
		if (access(pat, F_OK) == 0)
			return (pat);
		free(pat);
	}
	ft_free_array(path_list);
	return (0);
}

void	get_command(char **argv, char **envp, int argval)
{
	// char	**cmd;
	char	*cmd_path;
	int		i;
	pid_t    id;

	i = 0;
	(void)argval;
	// cmd = ft_split(argv[argval], 32);
	cmd_path = get_command_path(argv[0], envp);
	// if (!cmd_path)
	// {
	// 	while (cmd[i++])
	// 		free(cmd[i]);
	// 	// exit_error("path error");
	// }
	if (!cmd_path)
	{
		// free(cmd_path);
		printf("Command not found\n");
		// return ;
		// ft_free_array(cmd);
		// exit_error("Commmand or Command path not found");
	}
	id = fork();
	if (id == 0)
		execve(cmd_path, argv, envp);
	waitpid(id, NULL, 0);
	if (i == -1)
		ft_error("execve error\n");
		// exit_error("execve error.");
}
