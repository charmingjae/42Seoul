/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:11:14 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 11:31:09 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_do_convert(t_pack *pack, va_list ap)
{
	int		ret;
	char	type;

	ret = 0;
	type = pack->o_t;
	if (type == 'c')
		ret = ft_print_char(pack, va_arg(ap, int));
	else if (type == 's')
		ret = ft_print_string(pack, va_arg(ap, char *));
	else if (type == '%')
		ret = ft_print_percent(pack, '%');
	else if (type == 'd' || type == 'i')
		ret = ft_print_dori(pack, va_arg(ap, int));
	else if (type == 'u')
		ret = ft_print_dori(pack, va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		ret = ft_print_hex(pack, va_arg(ap, unsigned int));
	else if (type == 'p')
		ret = ft_print_hex(pack, va_arg(ap, t_ull));
	ft_init_struct(pack);
	return (ret);
}
