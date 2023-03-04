/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dori.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:28:46 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_bind_nbr(t_pack *pack, char **buf, t_ull i)
{
	int	g_max;

	g_max = ft_dori_max(pack, i);
	*buf = (char *)malloc(sizeof(char) * (g_max + 1));
	if (!(*buf))
		return (0);
	if (pack->dash > 0)
		ft_bind_nbr_yd(pack, *buf, i, g_max);
	else
		ft_bind_nbr_nd(pack, *buf, i, g_max);
	return (g_max);
}

int	ft_print_dori(t_pack *pack, long long i)
{
	char	*buf;
	int		get_m;

	if (i < 0)
	{
		pack->sign = -1;
		i = -i;
	}
	pack->t_num = i;
	get_m = ft_bind_nbr(pack, &buf, i);
	ft_putstr_len(buf, get_m);
	free(buf);
	return (get_m);
}
