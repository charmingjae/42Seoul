/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:29:47 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	sa(t_node *head)
{
	t_node	*target;

	if (head->size < 2)
		return ;
	target = head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	target->prev = target->next;
	target->next = target->next->next;
	target->prev->next = target;
	target->next->prev = target;
	write(1, "sa\n", 3);
}

void	sb(t_node *head)
{
	t_node	*target;

	if (head->size < 2)
		return ;
	target = head->next;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	target->prev = target->next;
	target->next = target->next->next;
	target->prev->next = target;
	target->next->prev = target;
	write(1, "sb\n", 3);
}

void	ss(t_node *a_head, t_node *b_head)
{
	sa(a_head);
	sb(b_head);
	write(1, "ss\n", 3);
}
