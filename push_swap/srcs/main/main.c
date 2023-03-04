/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:57:57 by mcha              #+#    #+#             */
/*   Updated: 2022/01/11 11:06:38 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

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
