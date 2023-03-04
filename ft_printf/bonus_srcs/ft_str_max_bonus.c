/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_max_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:29:02 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 12:14:54 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_str_max(t_pack *pack, int widths, int precs, char *arg)
{
	int	s_arg;

	s_arg = ft_strlen(arg);
	if (widths > precs && widths > s_arg)
		return (widths);
	else if (precs > s_arg)
	{
		if (pack->dash > 0)
			return (widths);
		if (s_arg >= widths)
			return (s_arg);
		return (precs);
	}
	else if (precs > 0 && precs < s_arg)
		return (precs);
	if (precs == 0 && pack->dot > 0)
		return (0);
	return (s_arg);
}
