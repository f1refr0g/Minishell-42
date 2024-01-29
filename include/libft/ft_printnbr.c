/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:16 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/10 13:44:21 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(n);
	len = ft_typestring(str);
	free (str);
	return (len);
}
