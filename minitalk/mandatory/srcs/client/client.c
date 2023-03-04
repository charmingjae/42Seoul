/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:37:17 by mcha              #+#    #+#             */
/*   Updated: 2022/01/21 20:56:32 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static int	exception(int ac, char **argv)
{
	if (ac != 3)
	{
		ft_printf("[Error] Expected usage : ./client [PID] [Message]\n");
		exit(1);
	}
	if (ft_atoi(argv[1]) == 0 || kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_printf("[Error] PID range exception occured\n");
		exit(1);
	}
	return (0);
}

static void	make_sigaction(void)
{
	struct sigaction	package;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	package.sa_mask = set;
	package.sa_handler = sig_handler;
	package.sa_flags = 0;
	sigaction(SIGUSR1, &package, NULL);
	sigaction(SIGUSR2, &package, NULL);
}

int	main(int ac, char **argv)
{
	int	pid;

	exception(ac, argv);
	pid = ft_atoi(argv[1]);
	ft_printf("[CLIENT PID : %d]\n", getpid());
	make_sigaction();
	post(pid, argv[2]);
	return (0);
}
