/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:21:19 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:25:55 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_do_check(t_pack *pack, char c)
{
	ft_check_flag(pack, c);
	ft_check_type(pack, c);
	ft_check_outr(pack);
}
