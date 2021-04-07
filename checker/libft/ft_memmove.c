/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:03:54 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/11 18:05:19 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	if (t_src < t_dst)
		while (++i <= len)
			t_dst[len - i] = t_src[len - i];
	else
		while (len-- > 0)
			*(t_dst++) = *(t_src++);
	return (dst);
}
