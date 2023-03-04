/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_nbr_yd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:14:14 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static char	ft_get_one(t_pack *pack, t_ull i, int idx)
{
	int	a;

	if (i == 0 && pack->dot > 0 && pack->width > pack->prec)
		return (' ');
	a = ft_get_pow((ft_nbrlen(pack, i) - idx - 1));
	i = (i / a) % 10;
	return (i + 48);
}

void	ft_bind_nbr_yd(t_pack *pack, char *buf \
	, t_ull i, int get_m)
{
	int	idx;
	int	z_idx;
	int	in_idx;

	idx = 0;
	z_idx = -1;
	in_idx = 0;
	if (pack->sign == -1)
		buf[idx++] = '-';
	else if (pack->space > 0)
		buf[idx++] = ' ';
	while (++z_idx < pack->prec - ft_nbrlen(pack, i) && pack->prec != 0)
		buf[idx++] = '0';
	while (idx < ft_nbrlen(pack, i) + 1 + z_idx && \
			in_idx < ft_nbrlen(pack, i) && idx < get_m)
		buf[idx++] = ft_get_one(pack, i, in_idx++);
	while (idx < get_m)
		buf[idx++] = ' ';
	buf[idx] = '\0';
}
