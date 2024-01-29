/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:20:18 by abeaudet          #+#    #+#             */
/*   Updated: 2023/06/26 18:03:40 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	k = ft_strlen(src);
	if (dstsize <= i)
		k += dstsize;
	else
		k += i;
	while (src[j] && (i + 1) < dstsize)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (k);
}
