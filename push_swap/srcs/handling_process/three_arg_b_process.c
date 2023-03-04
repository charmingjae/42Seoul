/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_arg_b_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:42:24 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	b_next_data_min(t_node *b, int get_max)
{
	if (b->next->next->next->data == get_max)
	{
		sb(b);
		rrb(b, B);
	}
	else if (b->next->next->data == get_max)
		rb(b, B);
}

void	b_doub_next_min(t_node *b, int get_max)
{
	if (b->next->data == get_max)
	{
		rrb(b, B);
		sb(b);
	}
	else if (b->prev->data == get_max)
		rrb(b, B);
}

void	b_prev_data_min(t_node *b, int get_max)
{
	if (b->next->data == get_max)
		return ;
	else if (b->next->next->data == get_max)
		sb(b);
}
