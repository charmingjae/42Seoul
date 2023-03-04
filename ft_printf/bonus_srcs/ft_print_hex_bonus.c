/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:04:03 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:15:21 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_bind_hex(t_pack *pack, char **buf, t_ull i)
{
	int	g_max;

	g_max = ft_hex_max(pack, i);
	*buf = (char *)malloc(sizeof(char) * (g_max + 1));
	if (!(*buf))
		return (0);
	if (pack->dash > 0)
		ft_bind_hex_yd(pack, *buf, i, g_max);
	else
		ft_bind_hex_nd(pack, *buf, i, g_max);
	return (g_max);
}

int	ft_print_hex(t_pack *pack, t_ull i)
{
	char	*buf;
	int		get_m;

	pack->h_num = i;
	pack->base = 16;
	get_m = ft_bind_hex(pack, &buf, i);
	ft_putstr_len(buf, get_m);
	free(buf);
	return (get_m);
}
