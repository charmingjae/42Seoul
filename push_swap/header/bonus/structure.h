/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:21:50 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:35:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef long long			t_ll;
typedef unsigned long long	t_ull;

typedef struct t_node
{
	int				data;
	int				size;
	struct t_node	*prev;
	struct t_node	*next;
}t_node;

#endif