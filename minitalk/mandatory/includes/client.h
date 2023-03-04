/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:37:34 by mcha              #+#    #+#             */
/*   Updated: 2022/01/21 19:25:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define SERVER 0

# include <signal.h>
# include <unistd.h>
# include "../srcs/ft_printf/headers/ft_printf.h"

void	sig_handler(int sig);
void	post(int pid, char *msg);
void	ft_putstr(char *str, int fd);

#endif