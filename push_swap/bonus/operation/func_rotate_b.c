/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:21:21 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:29:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

static void	go_tail(t_node *head, t_node *target)
{
	target->prev = head->prev;
	target->next = head;
	target->prev->next = target;
	target->next->prev = target;
}

static void	go_head(t_node *head, t_node *target)
{
	target->prev = head;
	target->next = head->next;
	target->prev->next = target;
	target->next->prev = target;
}

void	rb(t_node *head)
{
	t_node	*target;

	target = head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	go_tail(head, target);
}

void	rrb(t_node *head)
{
	t_node	*target;

	target = head->prev;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	go_head(head, target);
}
