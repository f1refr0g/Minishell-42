/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:49:53 by abeaudet          #+#    #+#             */
/*   Updated: 2024/02/06 14:27:42 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_array(char **array)
{
	int		i;

	if (!array)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (array[i])
			array[i] = ft_freeptr(array[i]);
	}
	array = ft_freeptr(array);
	return (NULL);
}

// void	**ft_free_array(char **array)
// {
// 	int		i;

// 	i = 0;
// 	if (!array)
// 		return (NULL);
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (NULL);
// }


