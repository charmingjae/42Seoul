/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_three_over_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:27:19 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

static void	min_top_a(t_node *a, int max)
{
	if (a->next->next->data == max)
	{
		ra(a, A);
		sa(a);
		rra(a, A);
	}
}

static void	min_mid_a(t_node *a, int max)
{
	sa(a);
	if (a->next->next->data == max)
	{
		ra(a, A);
		sa(a);
		rra(a, A);
	}
}

static void	min_bot_a(t_node *a, int max)
{
	if (a->next->data == max)
		sa(a);
	ra(a, A);
	sa(a);
	rra(a, A);
	sa(a);
}

void	hand_three_arg_over_a(t_node *a)
{
	int	get_max;
	int	get_min;

	find_max_min(a, &get_max, &get_min);
	if (a->next->data == get_min)
		min_top_a(a, get_max);
	else if (a->next->next->data == get_min)
		min_mid_a(a, get_max);
	else if (a->next->next->next->data == get_min)
		min_bot_a(a, get_max);
}
