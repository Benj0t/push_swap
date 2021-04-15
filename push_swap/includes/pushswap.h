/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:42:59 by bemoreau          #+#    #+#             */
/*   Updated: 2021/04/07 16:16:47 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSHWAP_H_
# define _PUSHWAP_H_
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			a_len;
	int			b_len;
	char		**oper;
}				t_stack;

int			hold_first(int *stack, int start, int end);
void		insert_down(t_stack *stack, int pos);
void		insert_down(t_stack *stack, int pos);
int			get_min_pos(int *stack, int len);
int			get_num_position(int *stack, int num);
int			first_sup(int *stack, int len, int num);
void		ft_swap(int *a, int *b);
void		swap(int *stack);
void		ss(t_stack *stack);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		rotate(int *stack, int len);
void		rr(t_stack *stack);
void		rev_rotate(int *stack, int len);
void		rrr(t_stack *stack);
void		resolve(t_stack *stack);
int			parse_duplicate(int *stack);
int			init_stack(t_stack *stack, int nb, char **operation);
int			init_a(int *stack, char **operation, int nb);
int			check_atoi(const char *str, int *bool);
char		**realloc_tab(char **tab, char *new);
int			check_num(char **arg);
int			check_args(char **tab);
void		free_tab(char **tab);
int			operation_check(char *operation);
int			valid_operations(char **operation, int i);
#endif