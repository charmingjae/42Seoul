/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_nbr_nd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:14:17 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	ft_get_one(t_pack *pack, t_ull i, int idx)
{
	int	a;

	if (i == 0 && pack->dot > 0 && pack->width > pack->prec)
		return (' ');
	a = ft_get_pow((ft_nbrlen(pack, i) - idx - 1));
	i = (i / a) % 10;
	return (i + 48);
}

static void	ft_bind_sign(t_pack *pack, char *buf, int *idx)
{
	if (pack->space && pack->sign > -1)
		buf[(*idx)++] = ' ';
	else if (pack->sign == -1)
		buf[(*idx)++] = '-';
	else if (pack->plus > 0 && pack->sign > -1)
		buf[(*idx)++] = '+';
}

static void	ft_bind_spac(t_pack *pack, char *buf, int *idx, int get_m)
{
	if (pack->prec && pack->prec > ft_nbrlen(pack, pack->t_num))
	{
		if (pack->space || pack->sign == -1 || pack->plus)
			while ((*idx) < get_m - pack->prec - 1)
				buf[(*idx)++] = ' ';
		else
			while ((*idx) < get_m - pack->prec)
				buf[(*idx)++] = ' ';
	}
	else
	{
		if (pack->space > 0 || pack->sign == -1 || pack->plus > 0)
			while ((*idx) < get_m - ft_nbrlen(pack, pack->t_num) - 1)
				buf[(*idx)++] = ' ';
		else
			while ((*idx) < get_m - ft_nbrlen(pack, pack->t_num))
				buf[(*idx)++] = ' ';
	}
}

static void	nbr_yzero(t_pack *pack, char *buf, int get_m)
{
	int	idx;
	int	i_idx;

	idx = 0;
	i_idx = 0;
	if ((pack->prec != 0 && pack->dot > 0) \
			|| (pack->prec == 0 && pack->dot > 0))
		ft_bind_spac(pack, buf, &idx, get_m);
	if (pack->space || pack->sign == -1 || pack->plus)
		ft_bind_sign(pack, buf, &idx);
	while (idx < get_m - ft_nbrlen(pack, pack->t_num))
		buf[idx++] = '0';
	while (idx < get_m)
		buf[idx++] = ft_get_one(pack, pack->t_num, i_idx++);
	buf[idx] = '\0';
}

void	ft_bind_nbr_nd(t_pack *pack, char *buf, t_ull i, int get_m)
{
	int	idx;
	int	i_idx;

	idx = 0;
	i_idx = 0;
	if (pack->zero > 0)
		nbr_yzero(pack, buf, get_m);
	else
	{
		ft_bind_spac(pack, buf, &idx, get_m);
		ft_bind_sign(pack, buf, &idx);
		while (idx < get_m - ft_nbrlen(pack, i) && pack->prec != 0)
			buf[idx++] = '0';
		while (idx < get_m)
			buf[idx++] = ft_get_one(pack, i, i_idx++);
		buf[idx] = '\0';
	}
}
