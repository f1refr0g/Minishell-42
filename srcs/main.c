#include "../include/minishell.h"

#include <stdlib.h>		// Free
#include <stdbool.h>	// Bool (true/false)

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data	data;
	int loop = 0;
	char	*input;

	//Initiation des struct etc.
	ft_init_minishell(&data, env);

	while (true && loop < 2)
	{
		input = readline("Minishell > ");	// Get User input inside char *input

		// Do something

		// free(input);					// Free the char *
	
		loop++;

	}
	printf("input is : %s\n", input);
	return (0);
}
