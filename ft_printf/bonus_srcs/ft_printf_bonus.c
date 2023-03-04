/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:45:23 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 10:15:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, s);
	ret = ft_do_print((char *)s, ap);
	va_end(ap);
	return (ret);
}
