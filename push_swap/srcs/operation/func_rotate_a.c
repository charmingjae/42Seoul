/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:50:15 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

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

void	ra(t_node *head, int flag)
{
	t_node	*target;

	target = head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	go_tail(head, target);
	if (flag == A)
		write(1, "ra\n", 3);
}

void	rra(t_node *head, int flag)
{
	t_node	*target;

	target = head->prev;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	go_head(head, target);
	if (flag == A)
		write(1, "rra\n", 4);
}
