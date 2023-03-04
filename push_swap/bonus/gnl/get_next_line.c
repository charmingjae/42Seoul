/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:11:54 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 20:43:42 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/get_next_line.h"

static char	*read_line(char *ptr, int fd)
{
	char	*buf;
	int		r_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r_size = 1;
	while (r_size > 0 && nl_index(ptr, '\n') == -1)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size == 0)
			break ;
		if (r_size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[r_size] = '\0';
		ptr = ft_strjoin(ptr, buf);
	}
	free(buf);
	return (ptr);
}

static char	*do_split(char *ptr)
{
	char	*line;
	int		idx;
	int		i;

	idx = 0;
	if (*ptr == '\0')
		return (NULL);
	while (ptr[idx] && ptr[idx] != '\n')
		idx++;
	if (ptr[idx] == '\n')
		idx++;
	line = (char *)malloc((idx + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < idx)
	{
		line[i] = ptr[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*do_move(char *ptr)
{
	char	*str;
	int		idx;
	int		i;

	idx = 0;
	while (ptr[idx] && ptr[idx] != '\n')
		idx++;
	if (ptr[idx] == '\n')
		idx++;
	if (ptr[idx] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(ptr) - idx + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (ptr[idx])
		str[i++] = ptr[idx++];
	str[i] = '\0';
	free(ptr);
	return (str);
}

char	*get_next_line(int fd, char **tmp)
{
	static char	*ptr[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ptr[fd] = read_line(ptr[fd], fd);
	if (!ptr[fd])
		return (NULL);
	line = do_split(ptr[fd]);
	ptr[fd] = do_move(ptr[fd]);
	*tmp = line;
	return (line);
}
