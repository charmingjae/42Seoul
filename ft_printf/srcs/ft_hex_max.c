/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:37:27 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	prec_big_len(t_pack *pack, int *prec_flag)
{
	if (pack->space > 0)
		(*prec_flag)++;
	else if (pack->sign == -1)
		(*prec_flag)++;
	else if (pack->plus > 0)
		(*prec_flag)++;
}

static void	prec_else(t_pack *pack, int *nbr_len, t_ull nbr)
{
	if (pack->sign == -1 && pack->plus < 1)
		(*nbr_len)++;
	if ((pack->space > 0 && pack->sign == 0) && pack->dash > 0)
		(*nbr_len)++;
	if (pack->prec > (*nbr_len))
		(*nbr_len) += (pack->prec - (*nbr_len));
	if (pack->plus > 0)
		(*nbr_len)++;
	if (pack->o_t == 'p')
		(*nbr_len) += 2;
	if (pack->hash > 0 && nbr != 0)
		(*nbr_len) += 2;
}

int	ft_hex_max(t_pack *p, t_ull nbr)
{
	int	nbr_len;
	int	prec_flag;

	nbr_len = ft_nbrlen(p, nbr);
	prec_flag = p->prec;
	if (p->width >= nbr_len && p->width > p->prec)
	{
		if (p->o_t == 'p' && p->width == nbr_len)
			return (p->width + 2);
		else if (p->o_t == 'p' && p->width > nbr_len && p->width - nbr_len < 2)
			return (p->width + (p->width - nbr_len));
		return (p->width);
	}
	else if (p->prec > nbr_len)
	{
		prec_big_len(p, &prec_flag);
		return (prec_flag);
	}
	else
	{
		if (p->prec == 0 && p->dot > 0 && nbr == 0)
			return (0);
		prec_else(p, &nbr_len, nbr);
		return (nbr_len);
	}
}
