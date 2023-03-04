/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:03:53 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:15:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_perc_bind(t_pack *pack, char **buf, char c)
{
	int	get_m;
	int	idx;

	idx = 0;
	get_m = ft_char_max(pack->width);
	*buf = (char *)malloc(sizeof(char) * (get_m + 1));
	if (!(*buf))
		return (-1);
	if (pack->dash > 0)
	{
		(*buf)[idx] = c;
		while (++idx < get_m)
			(*buf)[idx] = ' ';
	}
	else if (pack->dash < 1)
	{
		while (idx < get_m - 1)
			(*buf)[idx++] = ' ';
		(*buf)[idx++] = c;
	}
	(*buf)[idx] = '\0';
	return (get_m);
}

int	ft_print_percent(t_pack *pack, char c)
{
	char	*buf;
	int		get_m;

	buf = NULL;
	get_m = ft_perc_bind(pack, &buf, c);
	ft_putstr_len(buf, get_m);
	free(buf);
	return (get_m);
}
