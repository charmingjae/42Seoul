/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:38:37 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:38:00 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

void	do_free(t_node	*list)
{
	int		cnt;
	int		until;
	t_node	*tmp;

	cnt = 0;
	until = list->size + 1;
	tmp = list;
	while (cnt < until)
	{
		list = list->next;
		free(tmp);
		tmp = list;
		cnt++;
	}
}
