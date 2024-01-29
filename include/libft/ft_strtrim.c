/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:32:35 by abeaudet          #+#    #+#             */
/*   Updated: 2023/02/22 13:57:10 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		s;
	int		e;
	int		i;

	i = 0;
	s = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	e = ft_strlen(s1);
	while (s1[s] && ft_checkset(s1[s], set))
		s++;
	while (e > s && ft_checkset(s1[e - 1], set))
		e--;
	str = (char *)malloc(sizeof(char) *(e - s + 1));
	if (!str)
		return (NULL);
	while (s < e)
	{
		str[i++] = s1[s++];
	}
	str[i] = '\0';
	return (str);
}
