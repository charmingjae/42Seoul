/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:18:31 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 21:25:35 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	bind_value_philo(t_args *pck, t_ull idx, t_philo *philo)
{
	philo->args = pck;
	philo->philo_idx = idx + 1;
	philo->t_start_live = 0;
	philo->t_last_eat = 0;
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

void	connect_philo(t_args *pck, t_philo **arr)
{
	t_ull	idx;

	idx = 0;
	while (idx < pck->nbr_philo)
	{
		if (idx == pck->nbr_philo - 1)
			arr[idx]->next_philo = arr[0];
		else
			arr[idx]->next_philo = arr[idx + 1];
		idx++;
	}
}

void	do_unlink(sem_t *sem_p, sem_t *sem_f, sem_t *sem_fu)
{
	sem_close(sem_p);
	sem_unlink("printf");
	sem_close(sem_f);
	sem_unlink("fork");
	sem_close(sem_fu);
	sem_unlink("full");
}

int	create_philo(t_args *pck)
{
	t_philo			**arr_philo;
	sem_t			*sem_printf;
	sem_t			*sem_fork;
	sem_t			*sem_isfull;

	sem_printf = NULL;
	sem_fork = NULL;
	sem_isfull = NULL;
	arr_philo = (t_philo **)malloc(sizeof(t_philo *) * pck->nbr_philo);
	if (!arr_philo)
		return (ERROR);
	if (!bind_philo(pck, arr_philo))
	{
		free_philo(pck, arr_philo);
		return (ERROR);
	}
	if (!bind_sem(arr_philo, sem_printf, sem_fork, sem_isfull))
		return (ERROR);
	connect_philo(pck, arr_philo);
	philo_time(pck, arr_philo);
	do_unlink(sem_printf, sem_fork, sem_isfull);
	free_all(pck, arr_philo);
	return (1);
}
