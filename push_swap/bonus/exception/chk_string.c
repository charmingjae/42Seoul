/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:57:16 by mcha              #+#    #+#             */
/*   Updated: 2022/01/09 20:14:10 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

static int	chk_number(char *argv)
{
	while (*argv)
	{
		if (chk_digit(*argv) || chk_signal(*argv))
			argv++;
		else
			return (0);
	}
	return (1);
}

int	chk_string(char *argv)
{
	if (!chk_number(argv))
		return (0);
	return (1);
}
