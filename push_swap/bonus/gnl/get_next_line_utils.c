/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:20:33 by mcha              #+#    #+#             */
/*   Updated: 2022/01/07 18:59:30 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/get_next_line.h"

int	nl_index(const char *s, int c)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	char	*buf;
	int		idx;

	buf = (char *)malloc((ft_strlen(s1) + 1) + sizeof(char));
	if (!buf)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		buf[idx] = s1[idx];
		idx++;
	}
	buf[idx] = '\0';
	return (buf);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		f_idx;
	int		s_idx;

	if (!s1)
		s1 = ft_strdup("");
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	f_idx = 0;
	while (s1[f_idx])
	{
		str[f_idx] = s1[f_idx];
		f_idx++;
	}
	s_idx = 0;
	while (s2[s_idx])
		str[f_idx++] = s2[s_idx++];
	str[f_idx] = '\0';
	free(s1);
	return (str);
}
