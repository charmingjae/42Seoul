/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:36:55 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:36:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

void	insert_head(t_node *head, int data)
{
	t_node	*new_node;

	new_node = make_node(data);
	if (!new_node)
		return ;
	new_node->prev = head;
	new_node->next = head->next;
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	head->size += 1;
}

void	insert_tail(t_node *head, int data)
{
	t_node	*new_node;

	new_node = make_node(data);
	if (!new_node)
		return ;
	new_node->prev = head->prev;
	new_node->next = head;
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	head->size += 1;
}
