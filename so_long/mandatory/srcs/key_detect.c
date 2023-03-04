/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:34:57 by mcha              #+#    #+#             */
/*   Updated: 2022/02/02 22:18:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	detect_left_key(int keycode, t_map_info *info)
{
	char	left_block;

	left_block = info->m[info->p_r][info->p_c - 1];
	if (left_block != '1')
	{
		info->p_c -= 1;
		info->movements += 1;
		info->move_str = ft_itoa(info->movements);
		write(1, "Movements : ", 12);
		write(1, info->move_str, ft_strlen(info->move_str));
		write(1, "\n", 2);
		free(info->move_str);
		info->move_str = NULL;
	}
	return (keycode);
}

static int	detect_right_key(int keycode, t_map_info *info)
{
	char	right_block;

	right_block = info->m[info->p_r][info->p_c + 1];
	if (right_block != '1')
	{
		info->p_c += 1;
		info->movements += 1;
		info->move_str = ft_itoa(info->movements);
		write(1, "Movements : ", 12);
		write(1, info->move_str, ft_strlen(info->move_str));
		write(1, "\n", 2);
		free(info->move_str);
		info->move_str = NULL;
	}
	return (keycode);
}

static int	detect_down_key(int keycode, t_map_info *info)
{
	char	down_block;

	down_block = info->m[info->p_r + 1][info->p_c];
	if (down_block != '1')
	{
		info->p_r += 1;
		info->movements += 1;
		info->move_str = ft_itoa(info->movements);
		write(1, "Movements : ", 12);
		write(1, info->move_str, ft_strlen(info->move_str));
		write(1, "\n", 2);
		free(info->move_str);
		info->move_str = NULL;
	}
	return (keycode);
}

static int	detect_up_key(int keycode, t_map_info *info)
{
	char	up_block;

	up_block = info->m[info->p_r - 1][info->p_c];
	if (up_block != '1')
	{
		info->p_r -= 1;
		info->movements += 1;
		info->move_str = ft_itoa(info->movements);
		write(1, "Movements : ", 12);
		write(1, info->move_str, ft_strlen(info->move_str));
		write(1, "\n", 2);
		free(info->move_str);
		info->move_str = NULL;
	}
	return (keycode);
}

int	key_detect(int keycode, t_map_info *info)
{
	if (keycode == 0 && info->game_result == 0)
		detect_left_key(keycode, info);
	else if (keycode == 1 && info->game_result == 0)
		detect_down_key(keycode, info);
	else if (keycode == 2 && info->game_result == 0)
		detect_right_key(keycode, info);
	else if (keycode == 13 && info->game_result == 0)
		detect_up_key(keycode, info);
	else if (keycode == 53)
		game_exit(info);
	return (keycode);
}
