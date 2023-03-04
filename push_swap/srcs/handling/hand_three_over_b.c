/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_three_over_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:40:57 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

static void	min_top_b(t_node *b, int max)
{
	sb(b);
	rb(b, B);
	sb(b);
	rrb(b, B);
	if (b->next->next->data == max)
		sb(b);
}

static void	min_mid_b(t_node *b, int max)
{
	rb(b, B);
	sb(b);
	rrb(b, B);
	if (b->next->next->data == max)
		sb(b);
}

static void	min_bot_b(t_node *b, int max)
{
	if (b->next->next->data == max)
		sb(b);
}

void	hand_three_arg_over_b(t_node *a, t_node *b)
{
	int	get_max;
	int	get_min;

	find_max_min(b, &get_max, &get_min);
	if (b->next->data == get_min)
		min_top_b(b, get_max);
	else if (b->next->next->data == get_min)
		min_mid_b(b, get_max);
	else if (b->next->next->next->data == get_min)
		min_bot_b(b, get_max);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
