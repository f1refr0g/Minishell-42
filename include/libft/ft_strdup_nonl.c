/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nonl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:28:02 by abeaudet          #+#    #+#             */
/*   Updated: 2023/03/14 18:27:58 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_nonl(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(s1) - 1);
	if (dst == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s1) - 1)
	{
		dst[i++] = *s1++;
	}
	return (dst);
}
