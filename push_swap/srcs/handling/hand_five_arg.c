/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_five_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:55:19 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

int	get_mid_value(t_node *a)
{
	int	*arr;
	int	ret;

	arr = (int *)malloc(sizeof(int) * 5);
	arr[0] = a->next->data;
	arr[1] = a->next->next->data;
	arr[2] = a->next->next->next->data;
	arr[3] = a->next->next->next->next->data;
	arr[4] = a->next->next->next->next->next->data;
	sort_array(5, &arr);
	ret = arr[2];
	free(arr);
	return (ret);
}

static void	sort_a_five(int s, t_node *a, t_node *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value(a);
	while (s--)
	{
		if (a->next->data < mid)
		{
			pb(a, b);
			push++;
		}
		else
		{
			ra(a, A);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		rra(a, A);
}

static void	sort_b_five(int s, t_node *a, t_node *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value(b);
	while (s--)
	{
		if (b->next->data >= mid)
		{
			pa(a, b);
			push++;
		}
		else
		{
			rb(b, B);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		rrb(b, B);
}

void	hand_five_arg(int s, t_node *a, t_node *b, int type)
{
	if (type == A)
		sort_a_five(s, a, b);
	else
		sort_b_five(s, a, b);
	hand_three_arg(a, b, A);
	hand_two_arg(a, b, B);
}

void	hand_five_arg_init(t_node *a, t_node *b)
{
	int	cnt_pb;
	int	mid;

	cnt_pb = 0;
	mid = get_mid_value(a);
	while (1)
	{
		if (a->next->data < mid)
		{
			pb(a, b);
			cnt_pb++;
		}
		else
			ra(a, A);
		if (cnt_pb == 2)
			break ;
	}
	hand_three_arg(a, b, A);
	hand_two_arg(a, b, B);
}
