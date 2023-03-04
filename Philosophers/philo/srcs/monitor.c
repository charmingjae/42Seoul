/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:15:36 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 19:59:48 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_philo_die(t_args *pck, t_philo *philo, int *p_s)
{
	if (philo->t_last_eat + pck->tt_die <= calc_now())
	{
		*p_s = PHILO_UNSTABLE;
		printf("%llu %llu died\n", \
			calc_time(philo->t_start_live), philo->philo_idx);
	}
}

void	check_philo_eat(t_args *pck, t_philo *philo, t_ull *cnt_eat, int *p_s)
{
	if (pck->nbr_eat > 0 && philo->nbr_eat >= pck->nbr_eat)
	{
		if (philo->chk_eat == PHILO_NOT_EAT)
		{
			(*cnt_eat)++;
			philo->chk_eat = PHILO_ATE;
		}
		if (*cnt_eat >= pck->nbr_philo)
			*p_s = PHILO_UNSTABLE;
	}
}

void	check_conference_end(t_args *pck, t_philo **arr_philo, \
							t_ull *cnt_eat, int *p_s)
{
	t_ull	idx;

	idx = 0;
	while (42)
	{
		check_philo_die(pck, arr_philo[idx], p_s);
		check_philo_eat(pck, arr_philo[idx], cnt_eat, p_s);
		if (*p_s)
		{	
			idx = 0;
			while (idx < pck->nbr_philo)
				pthread_mutex_unlock(&(arr_philo[idx++]->mutex_fork));
			break ;
		}
		if (idx < pck->nbr_philo)
		{
			if (idx + 1 == pck->nbr_philo)
				idx = 0;
			else
				idx++;
		}
		usleep(100);
	}
}

void	monitor_death(t_args *pck, t_philo **arr_philo, int *p_s)
{
	t_ull	idx;
	t_ull	cnt;

	idx = 0;
	cnt = 0;
	check_conference_end(pck, arr_philo, &cnt, p_s);
	while (idx < pck->nbr_philo)
	{
		pthread_join(arr_philo[idx]->philo_tid, NULL);
		idx++;
	}
}
