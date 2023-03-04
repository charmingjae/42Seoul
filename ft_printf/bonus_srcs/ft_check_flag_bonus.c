/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:39 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_check_flag(t_pack *pack, char c)
{
	if (c == '-' && (pack)->zero < 1)
		(pack)->dash += 1;
	else if (c == '0' && !ft_isdigit((pack)->prev) && \
			(pack)->dash < 1 && (pack)->prec < 1 && pack->dot < 1)
		(pack)->zero += 1;
	else if (c == '.')
	{	
		(pack)->prev = '.';
		(pack)->dot += 1;
	}
	else if (c == '#')
		(pack)->hash += 1;
	else if (c == ' ' && (pack)->plus < 1)
		(pack)->space += 1;
	else if (c == '+' && (pack)->space < 1)
		(pack)->plus += 1;
}
