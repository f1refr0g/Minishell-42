/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:58:13 by abeaudet          #+#    #+#             */
/*   Updated: 2024/02/12 15:33:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// F pour trouver mon bn
int	ft_endline(const char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// concate mes str
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}

// F qui malloc
void	*ft_malloc(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}

// F qui sert a malloc une string
char	*ft_strdup(const char *s1)
{
	char	*strup;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i])
		i++;
	strup = ft_malloc(i + 1, sizeof * strup);
	if (!strup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strup[i] = s1[i];
		i++;
	}
	return (strup);
}

//fonction pour free plusieur ptr ( double pointeur pour avoir enough medmory)
void	ft_free(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}
