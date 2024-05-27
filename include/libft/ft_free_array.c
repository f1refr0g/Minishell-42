/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:49:53 by abeaudet          #+#    #+#             */
/*   Updated: 2024/05/27 17:44:02 by oldrolet         ###   ########.fr       */
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
