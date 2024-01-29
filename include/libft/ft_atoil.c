/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:39:04 by abeaudet          #+#    #+#             */
/*   Updated: 2023/08/07 15:03:57 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoil(const char *str)
{
	long int	entier;
	long int	signe;

	entier = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signe = -1;
	while (*str >= '0' && *str <= '9')
	{
		entier = entier * 10;
		entier = entier + ((*(str++)) - '0');
	}
	return (entier * signe);
}
