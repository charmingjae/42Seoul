/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:51:48 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 21:22:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define A 1
# define B 2
# define ALL 3

typedef long long			t_ll;
typedef unsigned long long	t_ull;

typedef struct t_node
{
	int				data;
	int				size;
	struct t_node	*prev;
	struct t_node	*next;
}t_node;

typedef struct t_cnt
{
	int	b_piv;
	int	s_piv;
	int	ra;
	int	rb;
	int	inter_ra;
	int	inter_rb;
	int	pa;
	int	pb;
	int	inter_pa;
	int	inter_pb;
}t_cnt;

#endif