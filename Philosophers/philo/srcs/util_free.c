/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:07:39 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 22:07:47 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_args *pck, t_philo **philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		free(philo[idx]);
		idx++;
	}
	free(philo);
}

void	free_all(t_args *pck, t_philo **philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		free(philo[idx]);
		idx++;
	}
	free(philo);
	free(pck);
}

void	destroy_fork_mutex(t_args *pck, t_philo **arr_philo)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		pthread_mutex_destroy(&(arr_philo[idx]->mutex_fork));
		idx++;
	}
}
