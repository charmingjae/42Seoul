/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:33:29 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 19:18:56 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

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
	int				*philo_status;
	t_args			*args;
	t_ull			nbr_philo;
	pthread_t		philo_tid;
	t_ull			philo_idx;
	int				chk_eat;
	t_ull			nbr_eat;
	t_ull			t_start_live;
	t_ull			t_last_eat;
	pthread_mutex_t	mutex_fork;
	pthread_mutex_t	*mutex_next_fork;
	pthread_mutex_t	*mutex_printf;
}t_philo;

#endif