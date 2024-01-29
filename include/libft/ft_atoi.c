/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:29:06 by abeaudet          #+#    #+#             */
/*   Updated: 2023/05/09 21:48:38 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	entier;
	int	signe;

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
