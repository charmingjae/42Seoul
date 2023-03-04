/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 22:42:50 by mcha              #+#    #+#             */
/*   Updated: 2022/02/03 00:01:11 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../includes/so_long_struct_bonus.h"
# include "../minilibx/mlx.h"
# include "../srcs/libft/libft.h"

/*
** Game
*/
void	play_game(t_map_info *info);

/*
** m
*/
void	catch_map_exception(char *map_name, t_map_info *info);

/*
** m util
*/
void	init_m(t_map_info *info);
void	bind_map(char *map_name, t_map_info *info);
void	put_tile(t_map_info *info, char m, int r, int c);
void	put_player(t_map_info *info, char m, int r, int c);
void	map_check_line(int fd, char *line, t_map_info *info);
void	map_check_top_bottom(int fd, char *line, t_map_info *info);

/*
** Utils
*/
int		game_exit(t_map_info *info);
void	free_m(t_map_info *info);
void	print_struct(t_map_info *info);
void	init_map_info(t_map_info **info);
void	free_fd_line_info(int fd, char *line, t_map_info *info);
char	*get_next_line(int fd, char **ret);

/*
** Detection
*/
int		key_detect(int keycode, t_map_info *info);

#endif