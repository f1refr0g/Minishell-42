/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:48:34 by abeaudet          #+#    #+#             */
/*   Updated: 2022/10/26 12:05:04 by abeaudet         ###   ########.fr       */
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
