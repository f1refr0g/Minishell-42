/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:49:53 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/07 13:46:04 by abeaudet         ###   ########.fr       */
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
