/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:43:39 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 19:46:26 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include "./philo_struct_bonus.h"

# define ERROR 0

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
**	Semaphore
*/
void	bind_full_sem(t_philo **arr, sem_t *s_isfull);
void	bind_pf_sem(t_philo **arr, sem_t *s_p, sem_t *s_f);
int		bind_sem(t_philo **arr, sem_t *sem_p, sem_t *sem_f, sem_t *sem_fu);

/*
**	Action
*/
void	philo_sig(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_say(char *str, t_philo *philo);
int		philo_full(t_philo *philo, pthread_t *thr);

/*
**	Philosopher
*/
int		create_philo(t_args *pck);
void	philo_time(t_args *pck, t_philo **arr);

/*
**	Time
*/
t_ull	calc_now(void);
void	philo_usleep(t_ull t);
t_ull	calc_time(t_ull time_start);

/*
**	Utility
*/
int		is_nbr(char *str);
t_ull	ft_atoull(char *str);
void	init_pck(t_args *pck);
void	ft_put_error(char *str);
void	free_all(t_args *pck, t_philo **philo);
void	free_philo(t_args *pck, t_philo **philo);
int		bind_args(t_args *pck, int ac, char **av);
int		bind_args_pck(t_args *pck, t_ull tmp, int idx);

#endif