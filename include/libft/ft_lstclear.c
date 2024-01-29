/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:58:10 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/01 15:14:37 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
	*lst = NULL;
}
