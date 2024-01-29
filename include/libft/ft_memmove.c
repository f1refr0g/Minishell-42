/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:30:22 by abeaudet          #+#    #+#             */
/*   Updated: 2022/10/26 12:05:42 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = -1;
	if (!dst && !src)
		return (NULL);
	if (dst2 > src2)
		while ((int)(--len) >= 0)
			dst2[len] = src2[len];
	else
		while (++i < len)
			dst2[i] = src2[i];
	return (dst);
}
