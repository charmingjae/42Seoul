/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:14:30 by mcha              #+#    #+#             */
/*   Updated: 2022/01/10 22:18:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

int	main(int ac, char **argv)
{
	int	is_error;

	is_error = 0;
	if (ac == 1)
		return (0);
	else
	{
		is_error = chk_error(argv);
		if (is_error)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else if (do_process(argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (0);
}
