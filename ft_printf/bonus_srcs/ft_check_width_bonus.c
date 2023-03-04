/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:54:43 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:14:42 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_check_width(t_pack *pack, char c)
{
	(pack)->width = ((pack)->width * 10) + (c - '0');
	(pack)->prev = c;
}
