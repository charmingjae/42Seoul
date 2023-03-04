/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_str_nd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:22:38 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static void	ft_prec_big(t_pack *pack, char *buf, int get_m, char *ele)
{
	int	idx;
	int	ele_idx;

	idx = 0;
	ele_idx = 0;
	if (pack->prec > (int)ft_strlen(ele))
		while (idx < get_m - (int)ft_strlen(ele))
			buf[idx++] = ' ';
	else
		while (idx < get_m - pack->prec)
			buf[idx++] = ' ';
	while (idx < get_m && ele_idx < pack->prec)
		buf[idx++] = ele[ele_idx++];
}

static void	ft_prec_small(char *buf, int get_m, char *ele)
{
	int	idx;
	int	ele_idx;

	idx = 0;
	ele_idx = 0;
	while (idx < get_m - (int)ft_strlen(ele))
		buf[idx++] = ' ';
	while (idx < get_m)
		buf[idx++] = ele[ele_idx++];
}

void	ft_bind_str_nd(t_pack *pack, char *buf, char *ele, int get_m)
{
	if (pack->prec > 0)
	{
		ft_prec_big(pack, buf, get_m, ele);
	}
	else
	{
		ft_prec_small(buf, get_m, ele);
	}
}
