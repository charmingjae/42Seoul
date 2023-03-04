/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dori_max_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:58:02 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:54 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static void	prec_big_len(t_pack *pack, int *prec_flag)
{
	if (pack->space > 0)
		(*prec_flag)++;
	else if (pack->sign == -1)
		(*prec_flag)++;
	else if (pack->plus > 0)
		(*prec_flag)++;
}

static void	prec_else(t_pack *pack, int *nbr_len)
{
	if (pack->sign == -1 && pack->plus < 1)
		(*nbr_len)++;
	if ((pack->space > 0 && pack->sign == 0))
		(*nbr_len)++;
	if (pack->prec > (*nbr_len))
		(*nbr_len) += (pack->prec - (*nbr_len));
	if (pack->plus > 0)
		(*nbr_len)++;
	if (pack->o_t == 'p')
		(*nbr_len) += 2;
}

int	ft_dori_max(t_pack *pack, t_ull nbr)
{	
	int	nbr_len;
	int	prec_flag;

	nbr_len = ft_nbrlen(pack, nbr);
	prec_flag = pack->prec;
	if (pack->width > pack->prec && pack->width > nbr_len)
		return (pack->width);
	else if (pack->prec > nbr_len)
	{
		prec_big_len(pack, &prec_flag);
		return (prec_flag);
	}
	else
	{
		if (pack->prec == 0 && pack->dot > 0 && nbr == 0 && pack->zero < 1)
			return (0);
		prec_else(pack, &nbr_len);
		return (nbr_len);
	}
}
