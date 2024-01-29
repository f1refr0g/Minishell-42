/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:16:43 by abeaudet          #+#    #+#             */
/*   Updated: 2024/01/29 12:57:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i <= n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	char		*d;
// 	const char	*s;
// 	size_t		i;

// 	d = (void *) dest;
// 	s = (void *) src;
// 	i = 0;
// 	if (!dest || !src)
// 		return (dest);
// 	if (n == 0 || (!s && !d) || s == d)
// 		return (d);
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }
