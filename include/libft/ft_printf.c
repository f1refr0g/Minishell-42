/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:25:04 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/22 12:05:49 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formchoice(va_list pick, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(pick, int));
	if (c == 's')
		len = len + ft_typestring(va_arg(pick, char *));
	if (c == 'p')
		len = len + ft_ptr(va_arg(pick, unsigned long int), 0);
	if (c == 'd' || c == 'i')
		len = len + ft_printnbr(va_arg(pick, int));
	if (c == 'u')
		len = len + ft_unsigned(va_arg(pick, unsigned int));
	if (c == 'x')
		len = len + ft_hexaprint(va_arg(pick, unsigned int), 'x');
	if (c == 'X')
		len = len + ft_hexaprint(va_arg(pick, unsigned int), 'X');
	if (c == '%')
		len = len + ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	pick;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(pick, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + ft_formchoice(pick, str[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(pick);
	return (len);
}
