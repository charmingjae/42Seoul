/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:11:11 by mcha              #+#    #+#             */
/*   Updated: 2022/01/10 22:17:08 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/mandatory/header.h"

static int	get_arrlen(char **argv)
{
	int	idx;

	idx = 1;
	while (argv[idx])
		idx++;
	return (idx - 1);
}

static void	do_bind(int *target, char **argv)
{
	int	idx;

	idx = 1;
	while (argv[idx])
	{
		target[idx - 1] = get_atol(argv[idx]);
		idx++;
	}
}

static int	chk_dup(int *target, int arr_len)
{
	int		*dup_proto;
	int		idx;
	t_ull	tmp;

	tmp = 0;
	idx = 0;
	dup_proto = (int *)malloc(sizeof(int) * 4294967296);
	if (!dup_proto)
		return (1);
	while (idx < arr_len)
	{
		if (target[idx] < 0)
			tmp = 2147483647 - (t_ull)(target[idx]);
		else
			tmp = target[idx];
		if (dup_proto[tmp] == 1)
		{
			free(dup_proto);
			return (1);
		}
		dup_proto[tmp] = 1;
		idx++;
	}
	free(dup_proto);
	return (0);
}

int	do_process(char **argv)
{
	int	idx;
	int	*target;

	idx = 0;
	target = (int *)malloc(sizeof(int) * get_arrlen(argv));
	if (!target)
		return (1);
	do_bind(target, argv);
	if (chk_dup(target, get_arrlen(argv)))
	{
		free(target);
		return (1);
	}
	do_link(target, get_arrlen(argv));
	return (0);
}
