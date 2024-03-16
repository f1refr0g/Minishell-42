#include "../include/minishell.h"

static int	ft_countwords(const char *str, char a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != a && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == a)
			j = 0;
		str++;
	}
	return (i);
}

static char	*word_up(const char *str, int debut, int fin)
{
	char	*word;
	int		i;

	i = 0;
	printf("wordup = %s\n", str);
	word = ft_calloc((fin - debut + 1), sizeof(char));
	if (!word)
		return (0);
	while (debut < fin)
	{
		word[i] = str[debut];
		i++;
		debut++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_tok(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		ind;
	int		qpos;
	char	**split;

	if (!s)
		return (0);
	split = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!split)
		return (0);
	i = -1;
	j = 0;
	ind = -1;
	qpos = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && ind < 0)
			ind = i;
		if (s[i] == '\'' || s[i] == '\"')
		{
			qpos = i + 1;
			while (s[qpos] && s[qpos] != s[i])
				qpos++;
			i = qpos;
		}
		else if ((s[i] == c || i == ft_strlen(s)) && ind >= 0)
		{
			split[j++] = word_up(s, ind, i);
			ind = -1;
		}
	}
	split[j] = NULL;
	return (split);
}
