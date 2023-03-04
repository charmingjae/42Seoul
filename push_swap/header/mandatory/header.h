/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:51:00 by mcha              #+#    #+#             */
/*   Updated: 2022/01/10 22:05:59 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include "structure.h"

/* Operation */
/* swap */
void	sa(t_node *head);
void	sb(t_node *head);
void	ss(t_node *a_head, t_node *b_head);

/* push */
void	pa(t_node *a_head, t_node *b_head);
void	pb(t_node *a_head, t_node *b_head);

/* rotate */
void	ra(t_node *head, int flag);
void	rb(t_node *head, int flag);
void	rra(t_node *head, int flag);
void	rrb(t_node *head, int flag);
void	rr(t_node *a_head, t_node *b_head);
void	rrr(t_node *a_head, t_node *b_head, int flag);

/* Process */
void	do_atob(int r, t_node *a, t_node *b, int *cnt);
void	do_btoa(int r, t_node *a, t_node *b, int *cnt);

/* Main */
int		do_process(char **argv);
void	do_link(int *tg, int len_arr);

/* Exception */
int		chk_space(char arg);
int		chk_digit(char arg);
int		chk_signal(char arg);
int		chk_error(char **argv);
int		chk_string(char *argv);
int		chk_empty(t_node *stack);
int		chk_ordered(t_node *stack);
int		chk_unordered(t_node *stack);
int		chk_args_except(int r, t_node *a, t_node *b, int type);

/* Handling */
void	hand_three_arg_over_a(t_node *a);
void	hand_five_arg_init(t_node *a, t_node *b);
void	hand_three_arg_over_b(t_node *a, t_node *b);
void	hand_one_arg(t_node *a, t_node *b, int type);
void	hand_two_arg(t_node *a, t_node *b, int type);
void	hand_three_arg(t_node *a, t_node *b, int type);
void	hand_five_arg(int s, t_node *a, t_node *b, int type);
void	hand_under_three_arg(int r, t_node *a, t_node *b, int type);

/* Handling Process */
void	a_next_data_min(t_node *a, int get_max);
void	a_doub_next_min(t_node *a, int get_max);
void	a_prev_data_min(t_node *a, int get_max);
void	b_next_data_min(t_node *b, int get_max);
void	b_doub_next_min(t_node *b, int get_max);
void	b_prev_data_min(t_node *b, int get_max);

/* Utils */
t_ll	get_atol(char *str);
t_node	*make_node(int value);
void	init_cnt(t_cnt **pck);
void	do_free(t_node	*list);
void	sort_array(int r, int **arr);
void	insert_head(t_node *head, int data);
void	insert_tail(t_node *head, int data);
void	get_pivot(int r, t_cnt *pck, t_node *stack);
void	init_head(t_node **a_head, t_node **b_head);
void	find_max_min(t_node *stack, int *get_max, int *get_min);

#endif