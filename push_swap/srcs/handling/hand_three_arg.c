/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_three_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:39:37 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	find_max_min(t_node *stack, int *get_max, int *get_min)
{
	int		*arr;
	t_node	*target;

	arr = (int *)malloc(sizeof(int) * 3);
	target = stack->next;
	arr[0] = target->data;
	arr[1] = target->next->data;
	arr[2] = target->next->next->data;
	sort_array(3, &arr);
	*get_max = arr[2];
	*get_min = arr[0];
	free(arr);
}

static void	hand_three_arg_a(t_node *a)
{
	int	get_max;
	int	get_min;

	find_max_min(a, &get_max, &get_min);
	if (a->next->data == get_min)
		a_next_data_min(a, get_max);
	else if (a->next->next->data == get_min)
		a_doub_next_min(a, get_max);
	else if (a->prev->data == get_min)
		a_prev_data_min(a, get_max);
}

static void	hand_three_arg_b(t_node *a, t_node *b)
{
	int	get_max;
	int	get_min;

	find_max_min(b, &get_max, &get_min);
	if (b->next->data == get_min)
		b_next_data_min(b, get_max);
	else if (b->next->next->data == get_min)
		b_doub_next_min(b, get_max);
	else if (b->prev->data == get_min)
		b_prev_data_min(b, get_max);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	hand_three_arg(t_node *a, t_node *b, int type)
{
	if (type == A && a->size == 3)
	{
		hand_three_arg_a(a);
		return ;
	}
	else if (type == B && b->size == 3)
	{
		hand_three_arg_b(a, b);
		return ;
	}
	if (type == A && a->size > 3)
	{
		hand_three_arg_over_a(a);
		return ;
	}
	else if (type == B && b->size > 3)
	{
		hand_three_arg_over_b(a, b);
		return ;
	}
}
