/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:40:26 by abeaudet          #+#    #+#             */
/*   Updated: 2024/01/29 13:06:25 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*ptr;
// 	size_t	i;

// 	i = 0;
// 	ptr = malloc(count * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (i < (count * size))
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
