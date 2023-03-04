/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:31:58 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 19:19:03 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	bind_fork_mutex(t_args *pck, t_philo **arr_philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		if (pthread_mutex_init(&(arr_philo[idx]->mutex_fork), NULL))
		{
			destroy_fork_mutex(pck, arr_philo);
			return (0);
		}
		idx++;
	}
	return (1);
}

int	bind_next_fork_mutex(t_args *pck, t_philo **arr_philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		if (idx == pck->nbr_philo - 1)
			arr_philo[idx]->mutex_next_fork = &(arr_philo[0]->mutex_fork);
		else
			arr_philo[idx]->mutex_next_fork = &(arr_philo[idx + 1]->mutex_fork);
		idx++;
	}
	return (1);
}

int	bind_printf_mutex(t_args *pck, t_philo **arr_philo, \
						pthread_mutex_t *mutex_printf)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		arr_philo[idx]->mutex_printf = mutex_printf;
		idx++;
	}
	return (1);
}

int	bind_mutex(t_args *pck, t_philo **arr_philo, pthread_mutex_t *mutex_printf)
{
	if (pthread_mutex_init(mutex_printf, NULL))
	{
		ft_put_error("[-] Fail to init printf mutex");
		return (0);
	}
	if (!bind_fork_mutex(pck, arr_philo))
	{
		ft_put_error("[-] Fail to bind fork mutex");
		return (0);
	}
	bind_next_fork_mutex(pck, arr_philo);
	bind_printf_mutex(pck, arr_philo, mutex_printf);
	return (1);
}
