/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:30:56 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/01 15:44:40 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_disnb(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_disnb(n / 10, str, i);
		ft_disnb(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

static long int	ft_nblen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_nblen(n) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	ft_disnb(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
