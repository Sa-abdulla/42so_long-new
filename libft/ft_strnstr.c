/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:50:49 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/16 13:49:08 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack [i] && i < len)
	{
		l = 0;
		while ((haystack[i + l] == needle[l]) && (needle[l]) && (i + l < len))
		{	
			l++;
		}
		if (!needle[l])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
