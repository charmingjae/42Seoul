/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:47:05 by mcha              #+#    #+#             */
/*   Updated: 2022/01/09 20:13:55 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

int	chk_signal(char arg)
{
	if (arg == '-' || arg == '+')
		return (1);
	return (0);
}

int	chk_space(char arg)
{
	if ((arg >= '\t' && arg <= '\r') || arg == ' ')
		return (1);
	return (0);
}

int	chk_digit(char arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

int	chk_number(char *argv)
{
	while (*argv)
	{
		if (chk_digit(*argv) || chk_space(*argv) || chk_signal(*argv))
			argv++;
		else
			return (0);
	}
	return (1);
}

int	chk_error(char **argv)
{
	t_ll	res;
	int		idx;

	res = 0;
	idx = 1;
	while (argv[idx])
	{
		if (chk_number(argv[idx]))
		{
			res = get_atol(argv[idx]);
			if (res < -2147483648 || res > 2147483647)
				return (1);
			if (!chk_string(argv[idx]))
				return (1);
		}
		else
			return (1);
		idx++;
	}
	return (0);
}
