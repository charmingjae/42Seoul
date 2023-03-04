/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:57:06 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 11:51:27 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_do_print(char *str, va_list ap)
{
	t_pack	*v_p;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	v_p = (t_pack *)malloc(sizeof(t_pack));
	if (!v_p)
		return (-1);
	v_p = ft_init_struct(v_p);
	while (str[i])
	{
		ft_check_whole(v_p, str[i], &ret);
		if (v_p->dot < 1 && v_p->percent > 0 && ft_isdigit(str[i]))
			ft_check_width(v_p, str[i]);
		else if (v_p->dot > 0 && v_p->percent > 0 \
				&& ft_isdigit(str[i]))
			ft_check_prec(v_p, str[i]);
		if (v_p->fin > 0)
			ret = ret + ft_do_convert(v_p, ap);
		i++;
	}
	free(v_p);
	return (ret);
}
