/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_is_quote_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:48:55 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:26:21 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	judge_is_quote_error(int bit)
{
	if (bit & SNQT || bit & DBQT)
		return (1);
	return (0);
}
