/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:27:52 by mcha              #+#    #+#             */
/*   Updated: 2022/01/08 23:45:36 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	do_link(int *tg, int len_arr)
{
	t_node	*a;
	t_node	*b;
	int		cnt_tg;
	int		cnt;

	cnt = 0;
	cnt_tg = 0;
	init_head(&a, &b);
	while (cnt_tg < len_arr)
	{
		insert_tail(a, tg[cnt_tg]);
		cnt_tg++;
	}
	free(tg);
	if (a->size == 5)
		hand_five_arg_init(a, b);
	else
		do_atob(a->size, a, b, &cnt);
	do_free(a);
	do_free(b);
}
