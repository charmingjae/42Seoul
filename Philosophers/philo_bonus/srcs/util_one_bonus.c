/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_one_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:44:19 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 19:19:06 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	is_nbr(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

void	init_pck(t_args *pck)
{
	pck->ac = 0;
	pck->nbr_philo = 0;
	pck->nbr_eat = 0;
	pck->tt_die = 0;
	pck->tt_eat = 0;
	pck->tt_sleep = 0;
}

t_ull	ft_atoull(char *str)
{
	t_ull	cnt;

	cnt = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (cnt > 18446744073709551615ULL)
			return (18446744073709551615ULL);
		cnt = cnt * 10 + (*str - '0');
		str++;
	}
	return (cnt);
}

int	bind_args_pck(t_args *pck, t_ull tmp, int idx)
{
	if (idx == 1)
	{
		pck->nbr_philo = tmp;
		if (pck->nbr_philo < 1)
			return (0);
	}
	else if (idx == 2)
		pck->tt_die = tmp * 1000;
	else if (idx == 3)
		pck->tt_eat = tmp * 1000;
	else if (idx == 4)
		pck->tt_sleep = tmp * 1000;
	else if (idx == 5)
	{
		if (tmp < 1)
			return (0);
		pck->nbr_eat = tmp;
	}
	return (1);
}

int	bind_args(t_args *pck, int ac, char **av)
{
	t_ull	tmp;
	int		idx;

	idx = 1;
	pck->ac = ac;
	while (av[idx])
	{
		tmp = ft_atoull(av[idx]);
		if (!bind_args_pck(pck, tmp, idx))
			return (0);
		idx++;
	}
	return (1);
}
