/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:43:07 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 19:42:39 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_say(char *str, t_philo *philo)
{
	if (*philo->philo_status)
		return ;
	pthread_mutex_lock(philo->mutex_printf);
	if (*philo->philo_status == PHILO_STABLE)
		printf("%llu %llu %s\n", \
			calc_time(philo->t_start_live), philo->philo_idx, str);
	pthread_mutex_unlock(philo->mutex_printf);
}

void	philo_eat(char *str, t_philo *philo)
{
	if (*philo->philo_status)
		return ;
	pthread_mutex_lock(philo->mutex_printf);
	if (*philo->philo_status == PHILO_STABLE)
		printf("%llu %llu %s\n", \
			calc_time(philo->t_start_live), philo->philo_idx, str);
	philo->nbr_eat++;
	philo->t_last_eat = calc_now();
	pthread_mutex_unlock(philo->mutex_printf);
	philo_usleep(philo->args->tt_eat);
}

void	action_pick_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex_fork));
	philo_say("has taken a fork", philo);
	pthread_mutex_lock(philo->mutex_next_fork);
	philo_say("has taken a fork", philo);
	philo_eat("is eating", philo);
	pthread_mutex_unlock(&(philo->mutex_fork));
	pthread_mutex_unlock(philo->mutex_next_fork);
	philo_say("is sleeping", philo);
	philo_usleep(philo->args->tt_sleep);
	philo_say("is thinking", philo);
}

void	*normal_philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	odd_philo_usleep(philo);
	while (*philo->philo_status == PHILO_STABLE)
		action_pick_eat(philo);
	return (NULL);
}

void	*spec_one_philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->mutex_fork));
	philo_say("has taken a fork", philo);
	while (*philo->philo_status == PHILO_STABLE)
		usleep(100);
	pthread_mutex_unlock(&(philo->mutex_fork));
	return (NULL);
}
