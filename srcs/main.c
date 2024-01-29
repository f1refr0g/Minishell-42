#include "../include/minishell.h"

#include <stdlib.h>		// Free
#include <stdbool.h>	// Bool (true/false)

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data	data;
	int i = 0;
	
	//Initiation des struct etc.
	// ft_memset(&data, 0, sizeof(t_data));
	ft_init_minishell(&data, env);

	while (true && data.state == 0)
	{
		data.prompt = readline("Minishell > ");	// Get User input inside char *input

		// Do something
		while (data.env[i])
		{
			printf("%s\n", data.env[i]);
			i++;
		}
		ft_exit(&data);
		// free(data.prompt);					// Free the char *
	
		// data.state++;

	}
	// ft_clean(&data);
	return (0);
}
