/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:24:25 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/17 10:08:23 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_puthex(unsigned int n, const char c)
{
	int	len;

	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar("0123456789abcdef"[n % 16]);
		else if (c == 'X')
			ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	len = ft_hexlen(n);
	return (len);
}

int	ft_hexaprint(unsigned int num, const char k)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_puthex(num, k);
	return (ft_hexlen(num));
}
