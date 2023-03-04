/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_ordered.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:35:11 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:39:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

int	chk_ordered(t_node *stack)
{
	long long	num;
	t_node		*target;

	num = -2147483649;
	target = stack->next;
	while (target != stack)
	{
		if ((long long)target->data > num)
			num = (long long)target->data;
		else
			return (0);
		target = target -> next;
	}
	return (1);
}
