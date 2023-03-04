/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:36:05 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 23:32:56 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	do_exit(t_args *pck, t_philo **arr)
{
	t_ull	idx;

	idx = 0;
	ft_put_error("[-] PID Error");
	while (idx < pck->nbr_philo)
		kill(arr[idx++]->pid, SIGINT);
	idx--;
	sem_close(arr[idx]->sem_fork);
	sem_unlink("fork");
	sem_close(arr[idx]->sem_printf);
	sem_unlink("printf");
	if (pck->nbr_philo > 0)
	{
		sem_close(arr[idx]->sem_isfull);
		sem_unlink("full");
	}
	exit(1);
}

t_ull	bind_time_pid(t_args *pck, t_philo **arr)
{
	t_ull	time;
	t_ull	idx;

	idx = 0;
	time = calc_now();
	while (idx < pck->nbr_philo)
	{
		arr[idx]->t_start_live = time;
		arr[idx]->t_last_eat = time;
		arr[idx]->pid = fork();
		if (!(arr[idx]->pid))
			return (idx);
		else if (arr[idx]->pid < 0)
		{
			do_exit(pck, arr);
			break ;
		}
		idx++;
	}
	return (0);
}

void	*chk_end(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->t_last_eat + philo->args->tt_die > calc_now())
		usleep(100);
	sem_wait(philo->sem_printf);
	printf("%llu %llu died\n", \
		calc_time(philo->t_start_live), philo->philo_idx);
	exit(1);
	return (NULL);
}

void	philo_prog(t_philo *philo)
{
	if (pthread_create(&(philo->tid), NULL, chk_end, philo))
	{
		ft_put_error("[-] Failed to create a thread");
		exit(1);
	}
	pthread_detach(philo->tid);
	philo_eat(philo);
}

void	philo_time(t_args *pck, t_philo **arr)
{
	pthread_t	thr;
	t_ull		ret;
	t_ull		idx;

	thr = NULL;
	ret = bind_time_pid(pck, arr);
	if (!(arr[ret]->pid))
		philo_prog(arr[ret]);
	else
	{
		if (pck->nbr_eat > 0)
		{
			if (!philo_full(arr[ret], &thr))
				return ;
		}
		waitpid(-1, NULL, 0);
		idx = -1;
		while (pck->nbr_eat > 0 && ++idx < pck->nbr_philo)
			sem_post(arr[ret]->sem_isfull);
		philo_sig(arr[ret]);
		pthread_join(thr, NULL);
	}
}
