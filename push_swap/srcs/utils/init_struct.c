/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:31:37 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

t_node	*make_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	init_head(t_node **a_head, t_node **b_head)
{
	*a_head = make_node(0);
	if (!a_head)
		return ;
	*b_head = make_node(0);
	if (!b_head)
		return ;
	(*a_head)->prev = *a_head;
	(*a_head)->next = *a_head;
	(*a_head)->size = 0;
	(*b_head)->prev = *b_head;
	(*b_head)->next = *b_head;
	(*b_head)->size = 0;
}

void	init_cnt(t_cnt **pck)
{
	*pck = (t_cnt *)malloc(sizeof(t_cnt));
	if (!(*pck))
		return ;
	(*pck)->b_piv = 0;
	(*pck)->s_piv = 0;
	(*pck)->ra = 0;
	(*pck)->rb = 0;
	(*pck)->inter_ra = 0;
	(*pck)->inter_rb = 0;
	(*pck)->pa = 0;
	(*pck)->pb = 0;
	(*pck)->inter_pa = 0;
	(*pck)->inter_pb = 0;
}
