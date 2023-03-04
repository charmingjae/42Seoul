/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:16:55 by mcha              #+#    #+#             */
/*   Updated: 2022/01/22 12:26:37 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static int	g_communication[2];

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_communication[SERVER] = 1;
		ft_printf("[-] Server is now so busy...\n");
		exit(0);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("[Notice] Successfully Sent\n");
		g_communication[SERVER] = 0;
		exit(0);
	}
}

static void	post_signal(int pid, int sig, int msg_len)
{
	int	bit;

	bit = 8;
	if (g_communication[SERVER] == 0)
	{
		while (bit-- > 0)
		{
			if ((sig >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (msg_len <= 100)
				usleep(125);
			else
				usleep(125);
		}
	}
}

static void	post_null(int pid)
{
	int	bit;

	bit = 8;
	while (bit-- > 0)
	{
		kill(pid, SIGUSR2);
		usleep(1500);
	}
}

void	post(int pid, char *msg)
{
	int	idx;
	int	msg_len;

	idx = 0;
	msg_len = ft_strlen(msg);
	if (g_communication[SERVER] == 0)
	{
		while (msg[idx])
			post_signal(pid, msg[idx++], msg_len);
		if (msg[idx] == '\0')
			post_null(pid);
		pause();
	}
}
