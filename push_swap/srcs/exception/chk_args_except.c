/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args_except.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:13:23 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

int	chk_args_except(int r, t_node *a, t_node *b, int type)
{
	if (type == A && chk_ordered(a))
		return (1);
	if (chk_ordered(a) && chk_empty(b))
		return (1);
	if (r <= 3)
	{
		hand_under_three_arg(r, a, b, type);
		return (1);
	}
	if (r == 5)
	{
		hand_five_arg(5, a, b, type);
		return (1);
	}
	else
		return (0);
}
