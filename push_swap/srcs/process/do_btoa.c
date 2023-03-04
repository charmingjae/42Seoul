/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:41:47 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

static void	back_to_orig_ra(t_node *a, t_node *b, t_cnt *var)
{
	int	cnt_rrr;
	int	rem;

	cnt_rrr = var->rb;
	rem = var->ra - cnt_rrr;
	while (cnt_rrr--)
		rrr(a, b, ALL);
	while (rem--)
		rra(a, A);
}

static void	back_to_orig_rb(t_node *a, t_node *b, t_cnt *var)
{
	int	cnt_rrr;
	int	rem;

	cnt_rrr = var->ra;
	rem = var->rb - cnt_rrr;
	while (cnt_rrr--)
		rrr(a, b, ALL);
	while (rem--)
		rrb(b, B);
}

static void	btoa_proc(t_node *a, t_node *b, t_cnt *pck)
{
	if (b->next->data <= pck->s_piv)
	{
		rb(b, B);
		pck->rb++;
	}	
	else
	{
		pa(a, b);
		pck->pa++;
		if (a->next->data <= pck->b_piv)
		{
			ra(a, A);
			pck->ra++;
		}
	}
}

void	do_btoa(int r, t_node *a, t_node *b, int *cnt)
{
	t_cnt	*pck;

	(*cnt)++;
	if (chk_args_except(r, a, b, B))
		return ;
	init_cnt(&pck);
	get_pivot(r, pck, b);
	while (r-- > 0)
		btoa_proc(a, b, pck);
	do_atob(pck->pa - pck->ra, a, b, cnt);
	if (pck->ra > pck->rb)
		back_to_orig_ra(a, b, pck);
	else
		back_to_orig_rb(a, b, pck);
	do_atob(pck->ra, a, b, cnt);
	do_btoa(pck->rb, a, b, cnt);
	free(pck);
}
