/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_arg_a_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:31:50 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	a_next_data_min(t_node *a, int get_max)
{
	if (a->next->next->next->data == get_max)
		return ;
	else if (a->next->next->data == get_max)
	{
		rra(a, A);
		sa(a);
	}
}

void	a_doub_next_min(t_node *a, int get_max)
{
	if (a->next->data == get_max)
		ra(a, A);
	else if (a->prev->data == get_max)
		sa(a);
}

void	a_prev_data_min(t_node *a, int get_max)
{
	if (a->next->data == get_max)
	{
		sa(a);
		rra(a, A);
	}
	else if (a->next->next->data == get_max)
		rra(a, A);
}
