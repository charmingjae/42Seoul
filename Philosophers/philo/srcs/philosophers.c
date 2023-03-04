/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:12:08 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 22:33:27 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	dinner_even_philos(t_args *pck, t_philo **arr_philo, \
						t_ull time_now, int *p_s)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		if (arr_philo[idx]->philo_idx % 2)
		{
			arr_philo[idx]->t_start_live = time_now;
			arr_philo[idx]->t_last_eat = time_now;
			arr_philo[idx]->philo_status = p_s;
			if (pthread_create(&(arr_philo[idx]->philo_tid), NULL, \
				normal_philo_action, arr_philo[idx]))
			{
				*p_s = PHILO_UNSTABLE;
				break ;
			}
		}
		idx++;
	}
}

void	dinner_odd_philos(t_args *pck, t_philo **arr_philo, \
						t_ull time_now, int *p_s)
{
	t_ull	idx;

	if (*p_s == PHILO_UNSTABLE || pck->nbr_philo == 1)
		return ;
	idx = 0;
	while (idx < pck->nbr_philo)
	{
		if (!(arr_philo[idx]->philo_idx % 2))
		{
			arr_philo[idx]->t_start_live = time_now;
			arr_philo[idx]->t_last_eat = time_now;
			arr_philo[idx]->philo_status = p_s;
			if (pthread_create(&(arr_philo[idx]->philo_tid), NULL, \
				normal_philo_action, arr_philo[idx]))
			{
				*p_s = PHILO_UNSTABLE;
				break ;
			}
		}
		idx++;
	}
}

void	dinner_spec_philos(t_philo **arr_philo, t_ull time_now, int *p_s)
{
	arr_philo[0]->t_start_live = time_now;
	arr_philo[0]->t_last_eat = time_now;
	arr_philo[0]->philo_status = p_s;
	if (pthread_create(&(arr_philo[0]->philo_tid), NULL, \
		spec_one_philo_action, arr_philo[0]))
		*p_s = PHILO_UNSTABLE;
}

void	philo_time(t_args *pck, t_philo **arr_philo, t_ull time_now)
{
	int	philo_status;

	philo_status = 0;
	if (pck->nbr_philo == 1)
		dinner_spec_philos(arr_philo, time_now, &philo_status);
	else
	{
		dinner_even_philos(pck, arr_philo, time_now, &philo_status);
		dinner_odd_philos(pck, arr_philo, time_now, &philo_status);
	}
	monitor_death(pck, arr_philo, &philo_status);
}
