/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_under_three_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:44:21 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	hand_under_three_arg(int r, t_node *a, t_node *b, int type)
{
	if (r == 3)
	{
		hand_three_arg(a, b, type);
		return ;
	}
	if (r == 2)
	{
		hand_two_arg(a, b, type);
		return ;
	}
	if (r == 1)
	{
		hand_one_arg(a, b, type);
		return ;
	}
}
