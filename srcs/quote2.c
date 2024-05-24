#include "../include/minishell.h"

int	contain_cash(char *input)
{
	int	i;

	i = 0;
	if (!input || !input[0])
		return (0);
	while (input[i])
	{
		if (input[i] == '$')
		{
			while (input[i + 1] && input[i + 1] == '$')
				i++;
			if (!input[i + 1])
				return (0);
			return (i);
		}
		i++;
	}
	return (0);
}
