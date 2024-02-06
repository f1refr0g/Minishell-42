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
		data.len = ft_strlen(data.prompt);
		if (contain_quote(data.prompt, data.len - 1, QUOTE))
			printf("Error quote \n");
		if (data.array)
			ft_free_array(data.array);
		data.array = ft_parse(&data);
		ft_expend(&data);

		// printf("count = %d\n", ft_count(data.prompt));

		// Do something
		// while (data.env[i])
		// {
		// 	printf("%s\n", data.env[i]);
		// 	i++;
		// }
		ft_pwd(&data);
		ft_env(&data);
		ft_exit(&data);	// free(data.prompt);					// Free the char *
	
		// data.state++;

	}
	// ft_clean(&data);
	return (0);
}
