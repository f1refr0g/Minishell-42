/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:39 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/10 14:05:46 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typestring(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_typestring("(null)"));
	while (str[i] != '\0')
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}
