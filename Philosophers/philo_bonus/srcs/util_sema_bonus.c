/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sema_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:15:29 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 19:42:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	bind_sem_full(t_philo **arr, sem_t *sem_p, sem_t *sem_f, sem_t *sem_fu)
{
	sem_unlink("full");
	sem_fu = sem_open("full", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if (sem_fu == SEM_FAILED)
	{
		sem_close(sem_f);
		sem_unlink("fork");
		sem_close(sem_p);
		sem_unlink("printf");
		return (ERROR);
	}
	bind_full_sem(arr, sem_fu);
	return (1);
}

int	bind_sem(t_philo **arr, sem_t *sem_p, sem_t *sem_f, sem_t *sem_fu)
{
	sem_unlink("fork");
	sem_f = sem_open("fork", O_CREAT, S_IRUSR | S_IWUSR, \
					arr[0]->args->nbr_philo);
	if (sem_f == SEM_FAILED)
		return (ERROR);
	sem_unlink("printf");
	sem_p = sem_open("printf", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (sem_p == SEM_FAILED)
	{
		sem_close(sem_f);
		sem_unlink("fork");
		return (ERROR);
	}
	bind_pf_sem(arr, sem_p, sem_f);
	if (arr[0]->args->nbr_eat > 0)
	{
		if (!bind_sem_full(arr, sem_p, sem_f, sem_fu))
			return (ERROR);
	}
	return (1);
}

void	bind_pf_sem(t_philo **arr, sem_t *s_p, sem_t *s_f)
{
	t_ull	idx;

	idx = 0;
	while (idx < arr[0]->args->nbr_philo)
	{
		arr[idx]->sem_printf = s_p;
		arr[idx]->sem_fork = s_f;
		arr[idx]->sem_isfull = NULL;
		idx++;
	}
}

void	bind_full_sem(t_philo **arr, sem_t *s_isfull)
{
	t_ull	idx;

	idx = 0;
	if (arr[0]->args->nbr_eat > 0)
	{
		while (idx < arr[0]->args->nbr_philo)
		{
			arr[idx]->sem_isfull = s_isfull;
			idx++;
		}
	}
}
