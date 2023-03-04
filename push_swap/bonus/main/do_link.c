/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:27:52 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 20:57:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"
#include "../../header/bonus/get_next_line.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s2 == 10)
		*s2 = 0;
	return (*s1 - *s2);
}

static int	catch_op(t_node *a, t_node *b, char *op)
{
	if (ft_strcmp("sa", op) == 0)
		sa(a);
	else if (ft_strcmp("sb", op) == 0)
		sb(b);
	else if (ft_strcmp("ss", op) == 0)
		ss(a, b);
	else if (ft_strcmp("pa", op) == 0)
		pa(a, b);
	else if (ft_strcmp("pb", op) == 0)
		pb(a, b);
	else if (ft_strcmp("ra", op) == 0)
		ra(a);
	else if (ft_strcmp("rb", op) == 0)
		rb(b);
	else if (ft_strcmp("rr", op) == 0)
		rr(a, b);
	else if (ft_strcmp("rra", op) == 0)
		rra(a);
	else if (ft_strcmp("rrb", op) == 0)
		rrb(b);
	else if (ft_strcmp("rrr", op) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

static void	do_sort(t_node *a, t_node *b)
{
	char	*ret;

	while (get_next_line(0, &ret) > 0)
	{
		if (!catch_op(a, b, ret))
		{
			write(2, "Error\n", 6);
			free(ret);
			do_free(a);
			do_free(b);
			exit(1);
		}
		free(ret);
	}
}

void	do_link(int *tg, int len_arr)
{
	t_node	*a;
	t_node	*b;
	int		cnt_tg;
	int		cnt;

	cnt = 0;
	cnt_tg = 0;
	init_head(&a, &b);
	while (cnt_tg < len_arr)
	{
		insert_tail(a, tg[cnt_tg]);
		cnt_tg++;
	}
	free(tg);
	do_sort(a, b);
	if (chk_ordered(a) && chk_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	do_free(a);
	do_free(b);
}
