/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:12:18 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 21:21:51 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int				nl_index(const char *s, int c);
char			*get_next_line(int fd, char **tmp);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);

#endif