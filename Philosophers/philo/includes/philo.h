/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:33:34 by mcha              #+#    #+#             */
/*   Updated: 2022/03/02 23:00:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "./philo_struct.h"

/*
**	ERROR
*/
# define ERROR 400

/*
**	PHILO STATUS
*/
# define PHILO_NOT_EAT 0
# define PHILO_ATE 1

/*
**	TABLE STATUS
*/
# define PHILO_STABLE 0
# define PHILO_UNSTABLE 1

/*
** Progress
*/
int		create_philo(t_args *pck);
void	philo_time(t_args *pck, t_philo **arr_philo, t_ull time_now);
int		bind_mutex(t_args *pck, t_philo **arr_philo, \
				pthread_mutex_t *mutex_printf);

/*
**	Utility
*/
int		is_nbr(char *str);
void	init_pck(t_args *pck);
void	ft_put_error(char *str);
void	free_all(t_args *pck, t_philo **philo);
void	free_philo(t_args *pck, t_philo **philo);
int		bind_args(t_args *pck, int ac, char **av);
void	destroy_fork_mutex(t_args *pck, t_philo **arr_philo);

/*
**	Time
*/
t_ull	calc_now(void);
t_ull	calc_time(t_ull time_start);
void	philo_usleep(t_ull t);

/*
**	Philosopher thread action
*/
void	odd_philo_usleep(t_philo *philo);
void	*normal_philo_action(void *arg);
void	*spec_one_philo_action(void *arg);

/*
**	Monitor
*/
void	monitor_death(t_args *pck, t_philo **arr_philo, int *p_s);

/*
**	Temp
*/
void	print_struct(t_args *pck);
void	print_philo(t_philo *philo);

#endif