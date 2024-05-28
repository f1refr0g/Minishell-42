/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:48:34 by abeaudet          #+#    #+#             */
/*   Updated: 2024/05/28 14:11:51 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	while (*s1)
	{
		dst[i++] = *s1++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup2(const char *s1)
{
	int		i;
	int		j;
	char	*str;
	int		trigger;

	trigger = 1;
	if (!s1 || !s1[0])
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] && trigger)
	{
		if (s1[j] == 34 && trigger == 1)
		{
			if (s1[j + 1] && s1[j + 1] == 34)
			{
				trigger = 1;
				j++;
			}
			else
				trigger = 2;
			j++;
		}
		else if (s1[j] == 39 && trigger == 1)
		{
			if (s1[j + 1] && s1[j + 1] == 39)
			{
				trigger = 1;
				j++;
			}
			else
				trigger = 3;
			j++;
		}
		else if ((trigger == 2 && s1[j] == 34) || (trigger == 3 && s1[j] == 39))
		{
			j++;
			trigger = 1;
		}
		else if ((trigger == 1 && s1[j] == ' ') || s1[j] == 0)
			trigger = 0;
		else
			str[i++] = s1[j++];
	}
	str[i] = 0;
	return (str);
}
