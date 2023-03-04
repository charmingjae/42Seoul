/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_atol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:54:55 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:38:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/header.h"

void	sort_array(int r, int **arr)
{
	int	cnt;
	int	idx;
	int	tmp;

	cnt = 0;
	idx = 0;
	tmp = 0;
	while (cnt < r)
	{
		idx = cnt;
		while (idx < r - 1)
		{
			if ((*arr)[cnt] > (*arr)[idx + 1])
			{
				tmp = (*arr)[cnt];
				(*arr)[cnt] = (*arr)[idx + 1];
				(*arr)[idx + 1] = tmp;
			}
			idx++;
		}
		cnt++;
	}
}

t_ll	get_atol(char *str)
{
	int			sign;
	int			cnt_sign;
	long long	result;

	sign = 1;
	cnt_sign = 0;
	result = 0;
	while (chk_space(*str))
		str++;
	while (chk_signal(*str))
	{
		if (*str++ == '-')
			sign *= -1;
		if (++cnt_sign > 1)
			return (0);
	}
	while (chk_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
