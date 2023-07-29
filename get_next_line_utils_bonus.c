/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbayir <sbayir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:06:24 by sbayir            #+#    #+#             */
/*   Updated: 2023/02/02 12:56:11 by sbayir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		s++;
	}
	if (!(char)c)
		return ((char *)(s));
	return (NULL);
}

int	ft_strlen(char *str, const char limit)
{
	int	i;

	i = 0;
	while (str[i] != limit && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s2)
		return (s1);
	str = malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_one_line(char *str)
{
	int		i;
	char	*one_line;
	int		len_line;

	if (str[0] == '\0')
		return (NULL);
	len_line = ft_strlen(str, '\n');
	one_line = malloc(sizeof(char) * len_line + 2);
	if (!one_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		one_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		one_line[i] = '\n';
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

char	*ft_discard_readline(char *str)
{
	int		i;
	char	*discarded;
	int		size;
	int		first_line_size;

	first_line_size = ft_strlen(str, '\n');
	size = (ft_strlen(str, '\0') - ft_strlen(str, '\n'));
	if (!*(str + first_line_size))
	{
		free(str);
		return (NULL);
	}
	discarded = malloc(sizeof(char) * (size) + 1);
	if (!discarded)
		return (NULL);
	i = 0;
	first_line_size++;
	while (str[first_line_size])
		discarded[i++] = str[first_line_size++];
	discarded[i] = '\0';
	free(str);
	return (discarded);
}
