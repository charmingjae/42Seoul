/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_hex_yd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:43:36 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	ft_get_one(t_pack *pack, t_ull i, int idx)
{
	t_ull	a;

	if (i == 0 && pack->dot > 0 && pack->width > pack->prec)
		return (' ');
	a = ft_get_hex_pow((ft_nbrlen(pack, i) - idx - 1));
	i = (i / a) % 16;
	if (pack->o_t == 'x' || pack->o_t == 'p')
		return ("0123456789abcdef"[i]);
	return ("0123456789ABCDEF"[i]);
}

static void	hash_contact(t_pack *pack, char *buf, int *idx, t_ull i)
{
	if ((pack->o_t == 'x' && pack->hash > 0 && i != 0) \
		|| pack->o_t == 'p')
	{
		buf[(*idx)++] = '0';
		buf[(*idx)++] = 'x';
	}
	else if (pack->o_t == 'X' && pack->hash > 0 && i != 0)
	{
		buf[(*idx)++] = '0';
		buf[(*idx)++] = 'X';
	}
}

void	ft_bind_hex_yd(t_pack *pack, char *buf \
	, t_ull i, int get_m)
{
	int	idx;
	int	z_idx;
	int	in_idx;

	idx = 0;
	z_idx = -1;
	in_idx = 0;
	hash_contact(pack, buf, &idx, i);
	if (pack->space > 0)
		buf[idx++] = ' ';
	while (++z_idx < pack->prec - ft_nbrlen(pack, i))
		buf[idx++] = '0';
	while (idx < ft_nbrlen(pack, i) + 2 + z_idx && \
	in_idx < ft_nbrlen(pack, i) && idx < get_m)
		buf[idx++] = ft_get_one(pack, i, in_idx++);
	while (idx < get_m)
		buf[idx++] = ' ';
	buf[idx] = '\0';
}
