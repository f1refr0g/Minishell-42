/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:27:35 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/01 14:36:19 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*new;

	i = 0;
	if (lst == NULL)
		return (i);
	new = lst;
	while (new != NULL)
	{
		new = new->next;
		i++;
	}
	return (i);
}
