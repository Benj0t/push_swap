/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:17:35 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/13 12:17:36 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;

	if (!(elem = ft_lstnew(NULL)))
	{
		ft_lstclear(&elem, del);
		return (NULL);
	}
	if (lst)
	{
		elem->content = f(lst->content);
		elem->next = ft_lstmap(lst->next, f, del);
	}
	return (elem);
}
