/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:49:35 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/15 14:17:50 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	cnt;
	int	done;

	i = 0;
	cnt = 0;
	done = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && !done)
			done = 1;
		else if (s[i] != c && done)
		{
			++cnt;
			done = 0;
		}
		++i;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**str;

	if (!s)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	words = 0;
	while (s[i] && words < word_count(s, c))
	{
		j = 0;
		while (s[i + j] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		str[words++] = ft_substr(s + i, 0, j);
		i += j;
	}
	str[words] = 0;
	return (str);
}
