/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_whole_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:51:03 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:39 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_check_whole(t_pack *pack, char c, int *ret)
{
	if ((pack)->percent == 0 && c == '%')
		(pack)->percent += 1;
	else if ((pack)->percent == 0 && c != '%')
	{
		ft_putchar(c);
		*ret += 1;
	}
	else if ((pack)->percent > 0 && c != '%')
		ft_do_check(pack, c);
	else if ((pack)->percent > 0 && c == '%')
		ft_do_check(pack, c);
}
