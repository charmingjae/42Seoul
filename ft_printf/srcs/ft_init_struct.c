/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:51:59 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

t_pack	*ft_init_struct(t_pack *pack)
{
	pack->target = NULL;
	pack->t_num = 0;
	pack->h_num = 0;
	pack->width = 0;
	pack->dash = 0;
	pack->plus = 0;
	pack->space = 0;
	pack->hash = 0;
	pack->zero = 0;
	pack->prec = 0;
	pack->percent = 0;
	pack->dot = 0;
	pack->tot_len = 0;
	pack->sign = 0;
	pack->fin = 0;
	pack->base = 10;
	pack->o_t = ' ';
	pack->prev = '?';
	return (pack);
}
