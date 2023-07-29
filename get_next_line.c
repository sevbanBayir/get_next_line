/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:05:06 by sbayir            #+#    #+#             */
/*   Updated: 2023/01/27 18:34:00 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*temp;
	int		read_bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp);
			free(str);
			return (NULL);
		}
		temp[read_bytes] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = ft_read(fd, store);
	if (!store)
		return (NULL);
	one_line = ft_one_line(store);
	store = ft_discard_readline(store);
	return (one_line);
}
