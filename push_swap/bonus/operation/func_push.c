/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:17:49 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 20:49:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

void	move_b_head(t_node *target, t_node *b_head)
{
	target->prev = b_head;
	target->next = b_head->next;
	target->prev->next = target;
	target->next->prev = target;
}

void	move_a_head(t_node *target, t_node *a_head)
{
	target->prev = a_head;
	target->next = a_head->next;
	target->prev->next = target;
	target->next->prev = target;
}

void	pb(t_node *a_head, t_node *b_head)
{
	t_node	*target;

	if (a_head->size < 1)
		return ;
	target = a_head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	move_b_head(target, b_head);
	a_head->size -= 1;
	b_head->size += 1;
}

void	pa(t_node *a_head, t_node *b_head)
{
	t_node	*target;

	if (b_head->size < 1)
		return ;
	target = b_head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	move_a_head(target, a_head);
	a_head->size += 1;
	b_head->size -= 1;
}
