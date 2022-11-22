/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:43 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/15 12:04:41 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s;

	i = 0;
	j = 0;
	s = 0;
	while (dst[j] && dstsize > j)
		j++;
	if (dstsize <= j)
		return (dstsize + ft_strlen(src));
	while ((j + 1) < dstsize && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	while (src[s])
		s++;
	if ((j - i) < dstsize)
	{
		dst[j] = '\0';
		return ((j - i) + s);
	}
	return (dstsize + s);
}
