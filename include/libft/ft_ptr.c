/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:08:17 by abeaudet          #+#    #+#             */
/*   Updated: 2023/06/26 18:03:58 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointlen(unsigned long int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

/* ne pas oublier de recall 0 pour la 1er apelle */
int	ft_ptr(unsigned long int nbr, int recall)
{
	int	i;

	i = 0;
	if (recall == 0)
	{
		ft_typestring("0x");
		if (nbr == 0)
		{
			ft_putchar('0');
			return (3);
		}
	}
	if (nbr >= 16)
	{
		ft_ptr(nbr / 16, 1);
		ft_ptr(nbr % 16, 1);
	}
	else
		ft_putchar("0123456789abcdef"[nbr % 16]);
	return (ft_pointlen(nbr) + 2);
}
