/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:51:33 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/13 10:54:21 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*explor;

	if (!new)
		return ;
	explor = *alst;
	if (explor)
	{
		while (explor->next != NULL)
			explor = explor->next;
		explor->next = new;
	}
	if (*alst == NULL)
		*alst = new;
	new->next = NULL;
}
