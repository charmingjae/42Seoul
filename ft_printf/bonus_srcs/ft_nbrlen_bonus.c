/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:20:21 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:15:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_nbrlen(t_pack *pack, t_ull nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	if (nbr == 0 && pack->prec != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= pack->base;
	}
	return (i);
}
