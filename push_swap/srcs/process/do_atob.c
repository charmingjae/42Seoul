/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:41:00 by mcha              #+#    #+#             */
/*   Updated: 2022/01/08 23:40:16 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

static void	back_to_orig_ra(t_node *a, t_node *b, int *cnt, t_cnt *var)
{
	int	cnt_rrr;
	int	rem;

	cnt_rrr = var->rb;
	rem = var->ra - cnt_rrr;
	if ((*cnt) > 0)
	{
		while (cnt_rrr--)
			rrr(a, b, ALL);
		while (rem--)
			rra(a, A);
	}
	else
	{
		while (cnt_rrr--)
			rrb(b, B);
	}
}

static void	back_to_orig_rb(t_node *a, t_node *b, int *cnt, t_cnt *var)
{
	int	cnt_rrr;
	int	rem;

	cnt_rrr = var->ra;
	rem = var->rb - cnt_rrr;
	if ((*cnt) > 0)
	{
		while (cnt_rrr--)
			rrr(a, b, ALL);
		while (rem--)
			rrb(b, B);
	}
	else
	{
		cnt_rrr = var->rb;
		while (cnt_rrr--)
			rrb(b, B);
	}
}

static void	atob_proc(t_node *a, t_node *b, t_cnt *pck)
{
	if (a->next->data > pck->b_piv)
	{
		ra(a, A);
		pck->ra++;
	}
	else
	{
		pb(a, b);
		pck->pb++;
		if (b->next->data > pck->s_piv)
		{
			rb(b, B);
			pck->rb += 1;
		}
	}
}

void	do_atob(int r, t_node *a, t_node *b, int *cnt)
{
	t_cnt	*pck;

	if (chk_args_except(r, a, b, A))
		return ;
	init_cnt(&pck);
	get_pivot(r, pck, a);
	while (r-- > 0)
		atob_proc(a, b, pck);
	if (pck->ra > pck->rb)
		back_to_orig_ra(a, b, cnt, pck);
	else
		back_to_orig_rb(a, b, cnt, pck);
	do_atob(pck->ra, a, b, cnt);
	do_btoa(pck->rb, a, b, cnt);
	do_btoa(pck->pb - pck->rb, a, b, cnt);
	free(pck);
}
