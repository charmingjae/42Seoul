/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prec_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:54:43 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:33 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_check_prec(t_pack *pack, char c)
{
	(pack)->prec = ((pack)->prec * 10) + (c - '0');
	(pack)->prev = c;
	if (pack->o_t != 'd' && pack->o_t != 'i' && pack->dash > 0)
		(pack)->zero = 0;
}
