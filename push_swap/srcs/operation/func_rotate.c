/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:24:55 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	rr(t_node *a_head, t_node *b_head)
{
	ra(a_head, ALL);
	rb(b_head, ALL);
	write(1, "rr\n", 3);
}

void	rrr(t_node *a_head, t_node *b_head, int flag)
{
	rra(a_head, flag);
	rrb(b_head, flag);
	write(1, "rrr\n", 4);
}
