/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:47 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 23:10:43 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_say(char *str, t_philo *philo)
{
	sem_wait(philo->sem_printf);
	printf("%llu %llu %s\n", \
		calc_time(philo->t_start_live), philo->philo_idx, str);
	sem_post(philo->sem_printf);
}

void	philo_eat(t_philo *philo)
{
	t_ull	cnt_eat;

	cnt_eat = 0;
	while (42)
	{
		sem_wait(philo->sem_fork);
		philo_say("has taken a fork", philo);
		sem_wait(philo->sem_fork);
		philo_say("has taken a fork", philo);
		philo_say("is eating", philo);
		philo->t_last_eat = calc_now();
		philo_usleep(philo->args->tt_eat);
		if (philo->args->nbr_eat > 0)
		{
			cnt_eat++;
			if (cnt_eat == philo->args->nbr_eat)
				sem_post(philo->sem_isfull);
		}
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		philo_say("is sleeping", philo);
		philo_usleep(philo->args->tt_sleep);
		philo_say("is thinking", philo);
	}
}

void	philo_sig(t_philo *philo)
{
	t_ull	n;

	n = 0;
	while (n++ < philo->args->nbr_philo)
	{
		kill(philo->pid, SIGINT);
		philo = philo->next_philo;
	}
}

void	*cnt_eat(void *arg)
{
	t_philo	*philo;
	t_ull	idx;

	idx = -1;
	philo = (t_philo *)arg;
	while (++idx < philo->args->nbr_philo)
		sem_wait(philo->sem_isfull);
	philo_sig(philo);
	return (NULL);
}

int	philo_full(t_philo *philo, pthread_t *thr)
{
	if (pthread_create(thr, NULL, cnt_eat, philo))
	{
		philo_sig(philo);
		return (0);
	}
	return (1);
}
