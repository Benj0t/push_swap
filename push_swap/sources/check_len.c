/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:00:00 by bemoreau          #+#    #+#             */
/*   Updated: 2021/12/11 19:38:44 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intlen(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		i = 2;
	while (nb / 10 != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	verify_args(char *arg)
{
	if (ft_atoui(arg) > 2147483647)
		return (1);
	return (0);
}

int	check_len(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i] > 11))
			return (1);
		if (ft_strlen(argv[i]) == 11 && \
			(argv[i][0] != '+' && argv[i][0] != '-'))
			return (1);
		if (verify_args(argv[i++]))
			return (1);
	}
	return (0);
}
