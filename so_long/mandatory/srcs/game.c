/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:31:13 by mcha              #+#    #+#             */
/*   Updated: 2022/02/02 23:17:34 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_map_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->width, info->height, "so_long");
}

void	init_images(t_map_info *info)
{
	int	x;
	int	y;

	info->img_w = \
		mlx_xpm_file_to_image(info->mlx, "./textures/wall.xpm", &x, &y);
	info->img_exit = \
		mlx_xpm_file_to_image(info->mlx, "./textures/exit.xpm", &x, &y);
	info->img_start = \
		mlx_xpm_file_to_image(info->mlx, "./textures/gd.xpm", &x, &y);
	info->img_p = \
		mlx_xpm_file_to_image(info->mlx, "./textures/ply.xpm", &x, &y);
	info->img_gd = \
		mlx_xpm_file_to_image(info->mlx, "./textures/gd.xpm", &x, &y);
	info->img_e_f = \
		mlx_xpm_file_to_image(info->mlx, "./textures/e1.xpm", &x, &y);
	info->img_e_s = \
		mlx_xpm_file_to_image(info->mlx, "./textures/e2.xpm", &x, &y);
	info->img_c_f = \
		mlx_xpm_file_to_image(info->mlx, "./textures/c1.xpm", &x, &y);
	info->img_c_s = \
		mlx_xpm_file_to_image(info->mlx, "./textures/c2.xpm", &x, &y);
}

void	init_enemy(t_map_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->rows)
	{
		y = 0;
		while (y < info->cols)
		{
			if (x % 7 == 3 && y % 5 == 2 && info->m[x][y] == '0')
				info->m[x][y] = 'D';
			y++;
		}
		x++;
	}
}

int	put_image_window(t_map_info *info)
{
	int	r;
	int	c;

	r = 0;
	while (r < info->rows)
	{
		c = 0;
		while (info->m[r][c])
		{
			put_tile(info, info->m[r][c], r * 64, c * 64);
			put_player(info, info->m[r][c], r, c);
			c++;
		}
		r++;
	}
	info->tick += 1;
	if (info->tick == 30)
		info->tick = 0;
	return (0);
}

void	play_game(t_map_info *info)
{
	info->width = 64 * info->cols;
	info->height = 64 * info->rows;
	init_window(info);
	init_images(info);
	init_enemy(info);
	mlx_loop_hook(info->mlx, put_image_window, info);
	mlx_hook(info->win, 2, 1L << 0, key_detect, info);
	mlx_hook(info->win, 17, 0, game_exit, info);
	mlx_loop(info->mlx);
}
