/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:47:02 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/16 13:31:02 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pt;
	int		i;
	int		j;

	if ((!s1 || !s2) ||
		(!(pt = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		pt[i++] = s1[j++];
	j = 0;
	while (s2[j])
		pt[i++] = s2[j++];
	pt[i] = '\0';
	return (pt);
}
