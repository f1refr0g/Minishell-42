#include "../include/minishell.h"

void	child(char **argv, char **envp, int *fd)
{
	int		file;

	file = open(argv[0], O_RDONLY, 0644);
	if (file == -1)
		exit_error("child infile invalid");
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(file, 0);
	get_command(argv, envp, 1);
	close(file);
	exit(1);
}

void	parent(char **argv, char **envp, int *fd)
{
	int		file;

	file = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		exit_error("parent outfile invalid");
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(file, 1);
	get_command(argv, envp, 2);
	close(file);
}


void    ft_execute(t_data *data)
{
    int i;
    pid_t pid;
    int fd[2];
    int prev_fd[2];

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
            if (i > 0)
            {
            close(fd[1]);
            dup2(fd[0], STDOUT_FILENO);
            close(fd[0]);
            }
            if (data->cmd_array[i + 1] != NULL)
            {
                close(fd[0]);
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
            }
            get_command(data->cmd_array[i], data->env, 1);
            i++;

        }
        else
        {
            if (i > 0)
            {
                close(prev_fd[0]);
                close(prev_fd[1]);   
            }

            prev_fd[0] = fd[0];
            prev_fd[1] = fd[1] ;
            i++;
        }
    }
    close(prev_fd[0]);
    close(prev_fd[1]);

    while (wait(NULL) > 0);

}