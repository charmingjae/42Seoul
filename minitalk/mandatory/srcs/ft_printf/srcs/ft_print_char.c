/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:44:03 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:07:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_char_bind(t_pack *pack, char **buf, int ele)
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
		(*buf)[idx] = (char)ele;
		while (++idx < get_m)
			(*buf)[idx] = ' ';
	}
	else if (pack->dash < 1)
	{
		while (idx < get_m - 1)
			(*buf)[idx++] = ' ';
		(*buf)[idx++] = (char)ele;
	}
	(*buf)[idx] = '\0';
	return (get_m);
}

int	ft_print_char(t_pack *pack, int ele)
{
	char	*buf;
	int		get_m;

	buf = NULL;
	get_m = ft_char_bind(pack, &buf, ele);
	ft_putstr_len(buf, get_m);
	free(buf);
	return (get_m);
}
