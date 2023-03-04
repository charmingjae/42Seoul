/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:47:57 by mcha              #+#    #+#             */
/*   Updated: 2022/01/21 16:01:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static void	make_sigaction(void)
{
	struct sigaction	package;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	package.sa_mask = set;
	package.sa_flags = SA_SIGINFO;
	package.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &package, NULL);
	sigaction(SIGUSR2, &package, NULL);
}

int	main(void)
{
	ft_printf("[SERVER PID : %d]\n", getpid());
	make_sigaction();
	while (1)
		pause();
	return (0);
}
