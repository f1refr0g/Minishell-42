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

void	*ft_other_free(void *p)
{
	if (p)
		free(p);
	return (0x0);
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
