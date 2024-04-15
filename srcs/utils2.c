#include "../include/minishell.h"

int	check_valid_quotes(char *input)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (!input || !input[0])
		return (0);
	while (input[i])
	{
		if (input[i] == 34 && trigger == 0)
			trigger = 1;
		else if (input[i] == 39 && trigger == 0)
			trigger = 2;
		else if (input[i] == 39 && trigger == 2)
			trigger = 0;
		else if (input[i] == 34 && trigger == 1)
			trigger = 0;
		i++;
	}
	if (trigger != 0)
		return (0);
	else
		return (1);
}

int	is_quote(int c)
{
	if (c == 34)
		return (1);
	else if (c == 39)
		return (2);
	else
		return (0);
}

int	has_quotes(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == 34)
			return (1);
		else if (str[i] == 39)
			return (2);
		i++;
	}
	return (0);
}
