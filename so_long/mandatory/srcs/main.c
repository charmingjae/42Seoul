/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:20:24 by mcha              #+#    #+#             */
/*   Updated: 2022/02/02 22:41:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	catch_exception(int ac)
{
	if (ac != 2)
	{
		perror("[Error] Expected usage : ./so_long [MAPFILE]\n");
		exit(1);
	}
}

static void	parse_map(char *map_name)
{
	t_map_info	*info;

	init_map_info(&info);
	catch_map_exception(map_name, info);
	bind_map(map_name, info);
	play_game(info);
	free_m(info);
	free(info);
}

int	main(int ac, char **argv)
{
	catch_exception(ac);
	parse_map(argv[1]);
	return (0);
}
