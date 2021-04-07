/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:22:32 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/07 16:50:42 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_err(void)
{
	char	*c;

	if (!(c = (char *)malloc(1)))
		return (NULL);
	c[0] = 0;
	return ((void *)c);
}

void			*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (size <= 0 || count <= 0)
		return (ft_err());
	len = size * count;
	i = 0;
	if (!(ret = (char *)malloc(len)))
		return (ft_err());
	while (i < len)
		ret[i++] = 0;
	return ((void *)ret);
}
