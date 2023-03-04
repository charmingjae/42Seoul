/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:37:40 by mcha              #+#    #+#             */
/*   Updated: 2022/06/09 19:27:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	proc_mlx(t_map_info **info)
{
	init_mlx(info);
	is_texture_valid(info);
	init_texture(info);
}