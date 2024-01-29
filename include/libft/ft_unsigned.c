/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:48:40 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/17 11:16:27 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getsign(unsigned long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	int	len;

	len = ft_getsign(n);
	if (n > 9)
	{
		ft_unsigned(n / 10);
	}
	ft_putchar("0123456789abcdef"[n % 10]);
	return (len);
}
