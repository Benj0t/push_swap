/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:00:05 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/11 18:05:05 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	if (!destination && !source)
		return (NULL);
	src = (unsigned char *)source;
	dest = (unsigned char *)destination;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
