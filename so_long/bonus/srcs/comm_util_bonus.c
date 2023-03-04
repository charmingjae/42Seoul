/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_util_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:28:42 by mcha              #+#    #+#             */
/*   Updated: 2022/02/03 15:14:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_fd_line_info(int fd, char *line, t_map_info *info)
{
	free(line);
	free(info);
	close(fd);
}

void	free_m(t_map_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->rows)
		free(info->m[idx++]);
	free(info->m);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	init_map_info(t_map_info **info)
{
	*info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!(*info))
		return ;
	(*info)->changed = 0;
	(*info)->rows = 0;
	(*info)->cols = 0;
	(*info)->exit_point = 0;
	(*info)->player_point = 0;
	(*info)->collect = 0;
	(*info)->width = 0;
	(*info)->height = 0;
	(*info)->tick = 0;
	(*info)->m = NULL;
	(*info)->movements = 0;
	(*info)->move_str = NULL;
	(*info)->p_r = 0;
	(*info)->p_c = 0;
	(*info)->player_initialized = 0;
	(*info)->game_result = 0;
}

void	init_m(t_map_info *info)
{
	info->m = (char **)malloc(sizeof(char *) * (info->rows + 1));
	if (!(info->m))
		return ;
}

int	game_exit(t_map_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}
