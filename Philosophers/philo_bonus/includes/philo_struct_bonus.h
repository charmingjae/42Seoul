/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:33:29 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 19:48:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_BONUS_H
# define PHILO_STRUCT_BONUS_H

typedef unsigned long long	t_ull;

typedef struct t_args
{
	int		ac;
	t_ull	nbr_philo;
	t_ull	tt_die;
	t_ull	tt_eat;
	t_ull	tt_sleep;
	t_ull	nbr_eat;
}t_args;

typedef struct t_philo
{
	pid_t			pid;
	pthread_t		tid;
	t_args			*args;
	t_ull			philo_idx;
	t_ull			t_start_live;
	t_ull			t_last_eat;
	sem_t			*sem_printf;
	sem_t			*sem_fork;
	sem_t			*sem_isfull;
	struct t_philo	*next_philo;
}t_philo;

#endif