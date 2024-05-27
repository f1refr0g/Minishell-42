/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:01 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:02 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	nb_of_words(char *s, int trigger, int i, int nb_wrds)
{
	if (s[i] == 39)
	{
		i++;
		trigger = 2;
	}
	else if (s[i] == 34)
	{
		i++;
		trigger = 1;
	}
	while (s[i])
	{
		if (s[i] == ' ' && trigger == 0)
			nb_wrds++;
		else if (s[i] == 34 && trigger == 1)
			trigger = 0;
		else if (s[i] == 39 && trigger == 2)
			trigger = 0;
		else if (s[i] == '|' && trigger == 0)
			nb_wrds++;
		i++;
	}
	return (nb_wrds);
}

int	mini_len(char *s, int start, int trigger, int len)
{
	while (s[start])
	{
		if (s[start] == 34 && trigger == 1)
			trigger = 0;
		else if (s[start] == 39 && trigger == 2)
			trigger = 0;
		else if (s[start] == 34 && trigger == 0)
			trigger = 1;
		else if (s[start] == 39 && trigger == 0)
			trigger = 2;
		else if (s[start] == ' ' && trigger == 0)
			return (len);
		else if (s[start] == '|' && trigger == 0)
			return (len);
		len++;
		start++;
	}
	return (len);
}

int	word_len(char *s, int start)
{
	int	trigger;
	int	len;

	trigger = 0;
	len = 0;
	if (s[start] == '|')
		return (1);
	if (s[start] == 39)
	{
		start++;
		len++;
		trigger = 2;
	}
	else if (s[start] == 34)
	{
		start++;
		len++;
		trigger = 1;
	}
	len += mini_len(s, start, trigger, len);
	return (len);
}

char	**no_name(char *s, int wrd_nb, int nb_wrds, char **split)
{
	int	len;
	int	i;

	i = 0;
	while (++wrd_nb < nb_wrds)
	{
		while (s[i] && s[i] == ' ')
			i++;
		len = word_len(s, i);
		split[wrd_nb] = ft_substr(s, i, len);
		if (split[wrd_nb][0] == '\0')
		{
			free(split[wrd_nb]);
			split[wrd_nb] = NULL;
			return (split);
		}
		i += len;
	}
	return (split);
}

char	**small_split(char *s)
{
	char	**split;
	int		nb_wrds;
	int		wrd_nb;

	nb_wrds = nb_of_words(s, 0, 0, 0) + 1;
	split = ft_calloc(nb_wrds + 1, sizeof(char *));
	if (!split)
		return (NULL);
	wrd_nb = -1;
	return (no_name(s, wrd_nb, nb_wrds, split));
}
