/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:15:31 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/01 15:30:17 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newelem = 0;
	while (lst)
	{
		newlst = ft_lstnew((*f)(lst->content));
		if (!newlst)
		{
			ft_lstclear(&newelem, del);
			return (NULL);
		}
		ft_lstadd_back(&newelem, newlst);
		lst = lst->next;
	}
	return (newelem);
}
