/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:18:46 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 19:37:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_ull	calc_now(void)
{
	struct timeval	times;

	gettimeofday(&times, NULL);
	return ((t_ull)times.tv_sec * 1000000 + (t_ull)times.tv_usec);
}

t_ull	calc_time(t_ull time_start)
{
	return ((calc_now() - time_start) / 1000);
}

void	odd_philo_usleep(t_philo *philo)
{
	t_ull	end_time;

	if (!(philo->philo_idx % 2))
	{
		end_time = (philo->args->tt_eat / 2) + calc_now();
		while (end_time > (t_ull)calc_now())
			usleep(100);
	}
}

void	philo_usleep(t_ull t)
{
	t_ull	end_time;

	end_time = t + calc_now();
	while (end_time > calc_now())
		usleep(100);
}
