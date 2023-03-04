/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util_two_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:35:28 by mcha              #+#    #+#             */
/*   Updated: 2022/02/03 15:14:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_tile(t_map_info *info, char m, int r, int c)
{
	if (m == '1')
		mlx_put_image_to_window(info->mlx, info->win, info->img_w, c, r);
	if (m == '0' || m == 'E' || m == 'C' || m == 'P' || m == 'D')
		mlx_put_image_to_window(info->mlx, info->win, info->img_gd, c, r);
	if (m == 'E')
		mlx_put_image_to_window(info->mlx, info->win, info->img_exit, c, r);
	if (m == 'C')
	{
		if (info->tick < 15)
			mlx_put_image_to_window(info->mlx, info->win, info->img_c_f, c, r);
		else
			mlx_put_image_to_window(info->mlx, info->win, info->img_c_s, c, r);
	}
	if (m == 'D')
	{
		if (info->tick < 15)
			mlx_put_image_to_window(info->mlx, info->win, info->img_e_f, c, r);
		else
			mlx_put_image_to_window(info->mlx, info->win, info->img_e_s, c, r);
	}
}

void	show_message_screen(t_map_info *info)
{
	mlx_string_put(info->mlx, info->win, 10, 24, 16777215, "Movements : ");
	info->move_str = ft_itoa(info->movements);
	mlx_string_put(info->mlx, info->win, 100, 24, 16777215, info->move_str);
	free(info->move_str);
	info->move_str = NULL;
	mlx_string_put(info->mlx, info->win, 10, 48, 16777215, "Remain : ");
	info->move_str = ft_itoa(info->collect);
	mlx_string_put(info->mlx, info->win, 100, 48, 16777215, info->move_str);
	free(info->move_str);
	info->move_str = NULL;
}

void	put_player(t_map_info *info, char m, int r, int c)
{
	if (m == 'P' && info->player_initialized == 0)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img_p,
			c * 64, r * 64);
		info->player_initialized = 1;
	}
	else if (info->player_initialized != 0 && info->p_c == c && info->p_r == r)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img_p,
			c * 64, r * 64);
		if (m == 'C' && info->p_r == r && info->p_c == c)
		{
			info->collect -= 1;
			info->m[r][c] = '0';
		}
		if (m == 'E' && info->p_r == r && info->p_c == c && info->collect == 0)
			info->game_result = 1;
		if (m == 'D' && info->p_r == r && info->p_c == c)
			info->game_result = 1;
	}
	show_message_screen(info);
}
