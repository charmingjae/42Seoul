/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info_wspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:39:32 by mcha              #+#    #+#             */
/*   Updated: 2022/06/14 13:09:14 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_info_wspace(t_map_info	*info)
{
	if (info == NULL)
		return ;
	if (info->wspace)
		free(info->wspace);
	info->wspace = NULL;
}
