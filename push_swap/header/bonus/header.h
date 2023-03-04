/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:15:20 by mcha              #+#    #+#             */
/*   Updated: 2022/01/09 20:11:01 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include "structure.h"

/* Main */
int		do_process(char **argv);
void	do_link(int *tg, int len_arr);

/* Operation */
/* swap */
void	sa(t_node *head);
void	sb(t_node *head);
void	ss(t_node *a_head, t_node *b_head);

/* push */
void	pa(t_node *a_head, t_node *b_head);
void	pb(t_node *a_head, t_node *b_head);

/* rotate */
void	ra(t_node *head);
void	rb(t_node *head);
void	rra(t_node *head);
void	rrb(t_node *head);
void	rr(t_node *a_head, t_node *b_head);
void	rrr(t_node *a_head, t_node *b_head);

/* Exception */
int		chk_space(char arg);
int		chk_digit(char arg);
int		chk_signal(char arg);
int		chk_error(char **argv);
int		chk_string(char *argv);
int		chk_empty(t_node *stack);
int		chk_ordered(t_node *stack);
int		chk_unordered(t_node *stack);

/* Utils */
t_ll	get_atol(char *str);
t_node	*make_node(int value);
void	do_free(t_node	*list);
void	sort_array(int r, int **arr);
void	insert_head(t_node *head, int data);
void	insert_tail(t_node *head, int data);
void	print_all(t_node *a_head, t_node *b_head);
void	init_head(t_node **a_head, t_node **b_head);
void	find_max_min(t_node *stack, int *get_max, int *get_min);

#endif