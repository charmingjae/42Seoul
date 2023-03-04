/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:18:31 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 22:08:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	bind_value_philo(t_args *pck, t_ull idx, t_philo *philo)
{
	philo->philo_status = 0;
	philo->args = pck;
	philo->nbr_philo = pck->nbr_philo;
	philo->philo_idx = idx + 1;
	philo->chk_eat = PHILO_NOT_EAT;
	philo->nbr_eat = 0;
	philo->t_start_live = 0;
	philo->t_last_eat = 0;
	philo->philo_status = PHILO_STABLE;
}

int	bind_philo(t_args *pck, t_philo **arr_philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		arr_philo[idx] = (t_philo *)malloc(sizeof(t_philo));
		if (!arr_philo[idx])
		{
			ft_put_error("[-] Fail to create the philosopher");
			return (0);
		}
		bind_value_philo(pck, idx, arr_philo[idx]);
		idx++;
	}
	return (1);
}

int	create_philo(t_args *pck)
{
	t_philo			**arr_philo;
	pthread_mutex_t	mutex_printf;

	arr_philo = (t_philo **)malloc(sizeof(t_philo *) * pck->nbr_philo);
	if (!arr_philo)
		return (ERROR);
	if (!bind_philo(pck, arr_philo) || \
		!bind_mutex(pck, arr_philo, &mutex_printf))
	{
		free_philo(pck, arr_philo);
		return (ERROR);
	}
	philo_time(pck, arr_philo, calc_now());
	destroy_fork_mutex(pck, arr_philo);
	pthread_mutex_destroy(&mutex_printf);
	free_all(pck, arr_philo);
	return (0);
}
