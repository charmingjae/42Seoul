/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:20:20 by mcha              #+#    #+#             */
/*   Updated: 2022/02/03 15:14:48 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_check_top_bottom(int fd, char *line, t_map_info *info)
{
	int	idx;

	idx = 0;
	while (line[idx] && line[idx] != '\n')
	{
		if (line[idx] != '1')
		{
			perror("Error\n[-] This top or bottom is not wall.\n");
			free_fd_line_info(fd, line, info);
			exit(1);
		}
		idx++;
	}
}

void	map_check_epc(char comp, t_map_info *info)
{
	if (comp == 'E')
		info->exit_point += 1;
	else if (comp == 'P')
		info->player_point += 1;
	else if (comp == 'C')
		info->collect += 1;
}

void	map_check_line(int fd, char *line, t_map_info *info)
{
	int	cnt;

	cnt = 0;
	while (line[cnt] && line[cnt] != '\n')
	{
		if ((cnt == 0 || cnt == info->cols - 1) && line[cnt] != '1')
		{
			perror("Error\n[-] This is not wall component.\n");
			free_fd_line_info(fd, line, info);
			exit(1);
		}
		map_check_epc(line[cnt], info);
		cnt++;
	}
}

void	bind_player(t_map_info *info, int r, int c)
{
	info->p_r = r;
	info->p_c = c;
}

void	bind_map(char *map_name, t_map_info *info)
{
	int		fd;
	int		cnt;
	int		idx;
	char	*line;

	init_m(info);
	fd = open(map_name, O_RDONLY);
	cnt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		idx = 0;
		info->m[cnt] = (char *)malloc(sizeof(char) * (info->cols + 1));
		while (line[idx])
		{
			info->m[cnt][idx] = line[idx];
			if (line[idx] == 'P')
				bind_player(info, cnt, idx);
			idx++;
		}
		info->m[cnt++][idx - 1] = '\0';
		free(line);
	}
	info->m[cnt] = NULL;
}
