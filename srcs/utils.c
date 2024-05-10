#include "../include/minishell.h"

int	ft_isonlyspace(int c)
{
	c = (unsigned char)c;
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

t_mini	*get_data(void)
{
	static t_mini	*mini;

	if (!mini)
	{
		mini = ft_calloc(1, sizeof(t_mini));
		if (!mini)
			return (mini);
	}
	return (mini);
}

int	is_sep(char *str)
{
	int	i;
	int	trigger;

	trigger = 0;
	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == 34 || str[i] == 39)
		trigger = 1;
	while (str[i])
	{
		if (trigger == 0 && (str[i] == '|' || str[i] == '>' || str[i] == '<'
				|| (str[i] == '>' && str[i + 1] && str[i + 1] == '>')
				|| (str[i] == '<' && str[i + 1] && str[i + 1] == '<')))
			return (1);
		i++;
	}
	return (0);
}

int	is_sep2(char *str)
{
	int	i;
	int	trigger;

	trigger = 0;
	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == 34 || str[i] == 39)
		trigger = 1;
	while (str[i])
	{
		if (trigger == 0 && (str[i] == '|'))
			return (1);
		i++;
	}
	return (0);
}

int	is_empty(char *prompt)
{
	int	i;

	i = 0;
	if (!prompt || !prompt[0] || prompt == NULL)
		return (1);
	while (prompt[i] && (ft_isonlyspace(prompt[i]) || prompt[i] == '|'))
	{
		if (prompt[i] == '|')
			return (0);
		i++;
	}
	if (prompt[i] == '\0')
		return (1);
	return (0);
}
