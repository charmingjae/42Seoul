/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_hex_nd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:03:30 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:16:16 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

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

static void	hex_yzero(t_pack *pack, char *buf, int get_m, int *idx)
{
	int	i_idx;

	i_idx = 0;
	if ((pack->dot < 1 && pack->prec == 0))
		while ((*idx) < get_m - ft_nbrlen(pack, pack->h_num))
			buf[(*idx)++] = '0';
	else if ((pack->dot > 0 && pack->prec != 0))
	{
		if (pack->prec > ft_nbrlen(pack, pack->h_num))
			while ((*idx) < get_m - pack->prec)
				buf[(*idx)++] = ' ';
		else if (pack->prec <= ft_nbrlen(pack, pack->h_num))
			while ((*idx) < get_m - ft_nbrlen(pack, pack->h_num))
				buf[(*idx)++] = ' ';
		while ((*idx) < get_m - ft_nbrlen(pack, pack->h_num))
			buf[(*idx)++] = '0';
	}
	while ((*idx) < get_m)
		buf[(*idx)++] = ft_get_one(pack, pack->h_num, i_idx++);
}

static void	hex_nzero(t_pack *pack, char *buf, int get_m, int *idx)
{
	int	i_idx;
	int	z_idx;

	i_idx = 0;
	z_idx = -1;
	if (((ft_nbrlen(pack, pack->h_num) == pack->width && pack->o_t != 'p') \
		|| (pack->hash < 1 && pack->o_t != 'p')) && pack->width > 0)
		while ((*idx) < get_m - ft_nbrlen(pack, pack->h_num))
			buf[(*idx)++] = ' ';
	while ((*idx) < get_m - ft_nbrlen(pack, pack->h_num) - 2 && pack->width > 0)
		buf[(*idx)++] = ' ';
	hash_contact(pack, buf, idx, pack->h_num);
	while (++z_idx < pack->prec - ft_nbrlen(pack, pack->h_num))
		buf[(*idx)++] = '0';
	while ((*idx) < get_m && i_idx < ft_nbrlen(pack, pack->h_num))
		buf[(*idx)++] = ft_get_one(pack, pack->h_num, i_idx++);
}

void	ft_bind_hex_nd(t_pack *pack, char *buf, t_ull i, int get_m)
{
	int	idx;
	int	z_idx;
	int	i_idx;

	idx = 0;
	i_idx = 0;
	z_idx = -1;
	if (pack->zero > 0)
	{
		hash_contact(pack, buf, &idx, i);
		hex_yzero(pack, buf, get_m, &idx);
	}
	else
		hex_nzero(pack, buf, get_m, &idx);
}
