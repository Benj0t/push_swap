/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:18:20 by bemoreau          #+#    #+#             */
/*   Updated: 2021/03/22 15:36:34 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_num(char **arg)
{
	int i;
	int j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_args(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "pa", 3))
			return (1);
	}
	return (0);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

int		operation_check(char *operation)
{
	if (!ft_strncmp(operation, "sa", 3))
		return (0);
	else if (!ft_strncmp(operation, "sb", 3))
		return (0);
	else if (!ft_strncmp(operation, "ss", 3))
		return (0);
	else if (!ft_strncmp(operation, "pa", 3))
		return (0);
	else if (!ft_strncmp(operation, "pb", 3))
		return (0);
	else if (!ft_strncmp(operation, "ra", 3))
		return (0);
	else if (!ft_strncmp(operation, "rb", 3))
		return (0);
	else if (!ft_strncmp(operation, "rr", 3))
		return (0);
	else if (!ft_strncmp(operation, "rra", 4))
		return (0);
	else if (!ft_strncmp(operation, "rrb", 4))
		return (0);
	else if (!ft_strncmp(operation, "rrr", 4))
		return (0);
	else
			return (1);
}

int		valid_operations(char **operation, int i)
{
	if (!operation)
		return (1);
	while (operation[i])
		if (operation_check(operation[i++]) == 1)
			return (1);
	return (0);
}
