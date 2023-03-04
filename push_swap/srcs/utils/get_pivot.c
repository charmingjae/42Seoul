/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:02:28 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:02:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

void	sort_array(int r, int **arr)
{
	int	cnt;
	int	idx;
	int	tmp;

	cnt = 0;
	idx = 0;
	tmp = 0;
	while (cnt < r)
	{
		idx = cnt;
		while (idx < r - 1)
		{
			if ((*arr)[cnt] > (*arr)[idx + 1])
			{
				tmp = (*arr)[cnt];
				(*arr)[cnt] = (*arr)[idx + 1];
				(*arr)[idx + 1] = tmp;
			}
			idx++;
		}
		cnt++;
	}
}

static void	select_pivot(int r, int *arr, t_cnt *pck)
{
	int	idx;

	if (r % 2 == 0)
	{	
		if (r == 4)
		{
			idx = r / 2 - 2;
			pck->s_piv = arr[idx];
			idx = r / 2 - 1;
			pck->b_piv = arr[idx];
			return ;
		}
		idx = r / 2 - 2;
		pck->s_piv = arr[idx];
		idx = r / 2 + 1;
		pck->b_piv = arr[idx];
	}
	else if (r % 2 == 1)
	{
		idx = r / 2 - 1;
		pck->s_piv = arr[idx];
		idx = r / 2 + 1;
		pck->b_piv = arr[idx];
	}
}

void	get_pivot(int r, t_cnt *pck, t_node *stack)
{
	t_node	*tmp;
	int		*arr;
	int		cnt;

	cnt = 0;
	arr = (int *)malloc(sizeof(int) * r);
	if (!arr)
		return ;
	tmp = stack->next;
	while (cnt < r)
	{
		arr[cnt] = tmp->data;
		tmp = tmp->next;
		cnt++;
	}
	sort_array(r, &arr);
	select_pivot(r, arr, pck);
	free(arr);
}
