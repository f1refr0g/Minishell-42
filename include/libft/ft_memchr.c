/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:12:30 by abeaudet          #+#    #+#             */
/*   Updated: 2022/10/26 12:42:17 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	b;

	i = 0;
	ptr = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (b == ptr[i])
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
