/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:32 by bemoreau          #+#    #+#             */
/*   Updated: 2019/11/16 11:33:37 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *str, char charset)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && str[i] != charset)
			count++;
		while (str[i] && str[i] != charset)
			i++;
	}
	return (count);
}

static int		ft_len_word(char const *str, char charset, int *p)
{
	int			count;

	count = 0;
	while (str[(*p)] && str[(*p)] == charset)
		(*p) = (*p) + 1;
	while (str[(*p)] && str[(*p)] != charset)
	{
		count++;
		(*p) = (*p) + 1;
	}
	return (count);
}

static void		ft_fill(char *tab, char const *str, char charset, int *p)
{
	int			j;

	j = 0;
	while (str[(*p)] && str[(*p)] == charset)
		(*p) = (*p) + 1;
	while (str[(*p)] && str[(*p)] != charset)
	{
		tab[j] = str[(*p)];
		j++;
		(*p) = (*p) + 1;
	}
}

static void		*ft_free(char ***tab, int i)
{
	while (--i >= 0)
		free((*tab)[i]);
	free(*tab);
	return (NULL);
}

char			**ft_split(char const *str, char charset)
{
	char	**tab;
	int		i;
	int		tmp;
	int		p;

	if (!str)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) *
		(ft_count_word(str, charset) + 1))))
		return (NULL);
	tab[ft_count_word(str, charset)] = 0;
	i = 0;
	p = 0;
	while (i < ft_count_word(str, charset))
	{
		tmp = ft_len_word(str, charset, &p);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (tmp + 1))))
			return (ft_free(&tab, i));
		tab[i++][tmp] = '\0';
	}
	i = 0;
	p = 0;
	while (i <= ft_count_word(str, charset))
		ft_fill(tab[i++], str, charset, &p);
	return (tab);
}
