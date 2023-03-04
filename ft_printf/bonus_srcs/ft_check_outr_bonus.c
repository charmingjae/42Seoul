/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_outr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:20:56 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:25:39 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_check_outr(t_pack *pack)
{
	if ((pack)->percent == 0 && (pack)->o_t != ' ')
	{
		(pack)->tot_len += 1;
	}
}
