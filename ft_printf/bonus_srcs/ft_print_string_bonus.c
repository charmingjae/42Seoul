/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:10:26 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:15:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_str_bind(t_pack *pack, char **buf, char *ele)
{
	int	get_m;

	get_m = ft_str_max(pack, pack->width, pack->prec, ele);
	*buf = (char *)malloc(sizeof(char) * (get_m + 1));
	if (!(*buf))
		return (-1);
	if (pack->dash > 0)
	{
		ft_bind_str_yd(pack, *buf, ele, get_m);
	}
	else if (pack->dash < 1)
	{
		ft_bind_str_nd(pack, *buf, ele, get_m);
	}
	(*buf)[get_m] = '\0';
	return (get_m);
}

int	ft_print_string(t_pack *pack, char *ele)
{
	char	*buf;
	int		get_m;

	buf = NULL;
	if (!ele)
		ele = "(null)";
	get_m = ft_str_bind(pack, &buf, ele);
	ft_putstr_len(buf, get_m);
	free(buf);
	return (get_m);
}
