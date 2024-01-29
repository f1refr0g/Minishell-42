/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intoverflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:55:52 by abeaudet          #+#    #+#             */
/*   Updated: 2023/05/28 11:58:12 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intoverflow(long int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}
