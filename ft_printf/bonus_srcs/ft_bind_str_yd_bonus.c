/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_str_yd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:26:49 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static void	ft_prec_big(t_pack *pack, char *buf, char *ele, int get_m)
{
	int	idx;

	idx = 0;
	while (idx < pack->prec && ele[idx])
	{
		buf[idx] = ele[idx];
		idx++;
	}
	while (idx < get_m)
		buf[idx++] = ' ';
}

static void	ft_prec_small(char *buf, char *ele, int get_m)
{
	int	idx;

	idx = 0;
	while (idx < (int)ft_strlen(ele))
	{
		buf[idx] = ele[idx];
		idx++;
	}
	while (idx < get_m)
		buf[idx++] = ' ';
}

void	ft_bind_str_yd(t_pack *pack, char *buf, char *ele, int get_m)
{
	if (pack->prec > 0)
	{
		ft_prec_big(pack, buf, ele, get_m);
	}		
	else
	{
		ft_prec_small(buf, ele, get_m);
	}
}
