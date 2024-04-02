#include "../include/minishell.h"

#include <stdlib.h>		// Free
#include <stdbool.h>	// Bool (true/false)

int	main(int ac, char **av, char **env)
{
	t_data			data;
	static t_mini	*mini;

	(void)av;
	if (ac > 1 || !env[0])
		return (launch_fail(env));
	//Initiation des struct etc.
	mini = get_data();
	ft_init_minishell(&data, env);
	while (1)
	{
		ft_signal_handler_parent(INTERACTIVE);
		mini->input = get_prompt("Minishell > ");
		//data.prompt = readline("Minishell > ");	// Get User input inside char *input
		// if (!data.prompt)
		// 	return (ft_exit(&data));
		//add_history(data.prompt);
		if (ft_isonlyspace(data.prompt) == 0)
		{
			data.len = ft_strlen(data.prompt);
			// printf("test home variable = %s\n", get_env_line("LESS", &data));
			// printf("str: %s\n", ft_dollar_switch(data.prompt, &data));
			// if (data.array)
			// 	ft_free_array(data.array);
			// data.array = ft_parse(&data);
			data.cmd_array = ft_commandarray(&data);
			// print_cmd_array(data.cmd_array);
			// if (data.cmd_array)
			// 	ft_execute(&data);
			// if (data.expended)
			// 	free(data.expended);
			// data.expended = ft_expend(&data);
		// printf("count = %d\n", ft_count(data.prompt));
			if ((valid_quote(data.prompt, ft_strlen(data.prompt) - 1, QUOTE) == true))
				printf(QUOTE_ERROR);
			ft_export(&data, data.cmd_array[0]);
			ft_echo(data.cmd_array[0]);

			ft_pwd(&data);
			ft_cd(&data, data.cmd_array[0]);
			ft_env(&data);
			ft_exit(&data);	// free(data.prompt);	// Free the char *
		// data.state++;
		}
	}
	// ft_clean(&data);
	return (0);
}
