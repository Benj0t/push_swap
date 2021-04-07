/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:29:50 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/16 17:36:59 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || (!(str = (char *)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	if (!(ft_strlen(s) < start))
		while (len-- > 0 && i < ft_strlen(s))
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
