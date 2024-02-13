#include "../include/minishell.h"

#include <stdlib.h>		// Free
#include <stdbool.h>	// Bool (true/false)

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data	data;
	// int i = 0;
	
	//Initiation des struct etc.
	// ft_memset(&data, 0, sizeof(t_data));
	ft_init_minishell(&data, env);

	while (1)
	{
		data.prompt = readline("Minishell > ");	// Get User input inside char *input
		if (ft_isonlyspace(data.prompt) == 0)
		{
			data.len = ft_strlen(data.prompt);
			if (data.array)
				ft_free_array(data.array);

			data.array = ft_parse(&data);

	//GET COMMAND IS EXITING ON NULL
			get_command(data.array, data.env, 0);

			if (data.expended)
				free(data.expended);
			data.expended = ft_expend(&data);

		// printf("count = %d\n", ft_count(data.prompt));

			if ((valid_quote(data.prompt, ft_strlen(data.prompt) - 1, QUOTE) == true))
				printf(QUOTE_ERROR);
			printf("1\n");
			ft_pwd(&data);
			ft_env(&data);
			ft_exit(&data);	// free(data.prompt);					// Free the char *

		// data.state++;
		}
	}
	// ft_clean(&data);
	return (0);
}
