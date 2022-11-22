/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:00:57 by sabdulla          #+#    #+#             */
/*   Updated: 2022/06/14 19:13:42 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *s)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (!ft_strchr_mod(s, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin_mod(s, str);
	}
	free(str);
	return (s);
}

char	*ft_write(char *str)
{
	char	*s;
	int		l;
	int		i;

	l = 0;
	i = 0;
	if (!str[0])
		return (NULL);
	while (str[l] && str[l] != '\n')
		l++;
	s = (char *)malloc(sizeof(char) * (l + 2));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_copy(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_mod(s) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
	{
		free (s);
		return (NULL);
	}
	str = ft_write(s);
	s = ft_copy(s);
	return (str);
}
