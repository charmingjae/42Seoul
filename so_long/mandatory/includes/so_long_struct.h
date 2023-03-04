/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:08:26 by mcha              #+#    #+#             */
/*   Updated: 2022/02/02 22:42:40 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef struct s_map_info
{
	int		changed;
	int		rows;
	int		cols;
	int		exit_point;
	int		player_point;
	int		collect;
	int		width;
	int		height;
	char	**m;
	int		tick;
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_exit;
	void	*img_start;
	void	*img_p;
	void	*img_gd;
	void	*img_e_f;
	void	*img_e_s;
	void	*img_c_f;
	void	*img_c_s;
	int		movements;
	char	*move_str;
	int		p_r;
	int		p_c;
	int		player_initialized;
	int		game_result;
}t_map_info;

#endif