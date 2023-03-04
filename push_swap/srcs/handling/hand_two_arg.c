/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_two_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:17:28 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	hand_two_arg(t_node *a, t_node *b, int type)
{
	if (type == A)
	{
		if (a->next->data > a->next->next->data)
			sa(a);
	}
	else if (type == B)
	{
		if (b->next->data < b->next->next->data)
			sb(b);
		pa(a, b);
		pa(a, b);
	}
}
