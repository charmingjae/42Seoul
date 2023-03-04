/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:54:38 by mcha              #+#    #+#             */
/*   Updated: 2022/01/21 20:49:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static void	msg_proc(int sig, unsigned char *msg, int *bit)
{
	if (sig == SIGUSR1)
		*msg |= 1;
	else if (sig == SIGUSR2)
		*msg |= 0;
	(*bit)++;
	if ((*bit) != 8)
		(*msg) <<= 1;
}

static void	ft_null(siginfo_t *siginfo, int *client_pid, int *status)
{
	write(1, "\n", 2);
	kill(siginfo->si_pid, SIGUSR2);
	*client_pid = 0;
	*status = 0;
}

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				bit = 0;
	static pid_t			client_pid = 0;
	static int				status = 0;
	static unsigned char	msg = 0;

	if (client_pid == siginfo->si_pid || status == 0)
	{
		msg_proc(sig, &msg, &bit);
		client_pid = siginfo->si_pid;
		status = 1;
		if (bit == 8)
		{
			if (msg == '\0')
				ft_null(siginfo, &client_pid, &status);
			else
				ft_printf("%c", msg);
			msg = 0;
			bit = 0;
		}
		(void)context;
	}
	else
		kill(siginfo->si_pid, SIGUSR1);
}
