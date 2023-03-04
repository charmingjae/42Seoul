/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:16:06 by mcha              #+#    #+#             */
/*   Updated: 2022/03/03 23:33:39 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_put_error(char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	except_argc(int ac)
{
	if (ac == 1)
		return (0);
	if (ac != 5 && ac != 6)
	{
		ft_put_error("[-] Expected usage : ./philo arg_1 arg_2 \
					arg_3 arg_4 [optional]");
		return (0);
	}
	return (1);
}

int	except_argv(char **av)
{
	int	idx;

	idx = 1;
	while (av[idx])
	{
		if (!is_nbr(av[idx]))
		{
			ft_put_error("[-] Arguments error");
			return (0);
		}
		idx++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_args	*pck;

	if (!except_argc(ac) || !except_argv(av))
		return (1);
	pck = (t_args *)malloc(sizeof(t_args));
	if (!pck)
		return (0);
	init_pck(pck);
	if (!bind_args(pck, ac, av) || !create_philo(pck))
	{
		ft_put_error("[-] Error occured");
		free(pck);
		return (0);
	}
	return (0);
}
