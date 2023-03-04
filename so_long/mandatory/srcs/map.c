/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:40:58 by mcha              #+#    #+#             */
/*   Updated: 2022/02/03 15:29:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_name_exception(char *map_name)
{
	int		fd;
	char	c[1];

	fd = open(map_name, O_RDONLY);
	if (fd < 0 || ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4))
	{
		perror("Error\n[-] Wrong map file.\n");
		close(fd);
		exit(1);
	}
	else
	{
		read(fd, c, 1);
		if (!ft_isprint(c[0]))
		{
			perror("Error\n[-] Empty file.\n");
			close(fd);
			exit(1);
		}
	}
	close(fd);
}

static void	map_recs_exception(char *map_name, t_map_info *info)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	info->cols = (int)ft_strlen(get_next_line(fd, &line)) - 1;
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (info->cols != (int)(ft_strlen(line) - 1))
		{
			perror("Error\n[-] This map is not rectangular\n");
			free_fd_line_info(fd, line, info);
			exit(1);
		}
		info->rows++;
		free(line);
	}
	info->rows++;
	close(fd);
}

static void	map_comp_exception(char *map_name, t_map_info *info)
{
	int		fd;
	int		cnt;
	char	*line;

	cnt = 0;
	fd = open(map_name, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (cnt == 0 || cnt == info->rows - 1)
			map_check_top_bottom(fd, line, info);
		else
			map_check_line(fd, line, info);
		cnt++;
		free(line);
	}
	if (info->exit_point < 1 || info->player_point != 1 || info->collect < 1)
	{
		perror("Error\n[-] E, P, C components error\n");
		close(fd);
		free(info);
		exit(1);
	}
	close(fd);
}

void	catch_map_exception(char *map_name, t_map_info *info)
{
	map_name_exception(map_name);
	map_recs_exception(map_name, info);
	map_comp_exception(map_name, info);
}
