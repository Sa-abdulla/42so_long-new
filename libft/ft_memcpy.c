/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:57:25 by sabdulla          #+#    #+#             */
/*   Updated: 2021/12/27 13:36:15 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sr;

	i = 0;
	dest = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		dest[i] = sr[i];
		i++;
		n--;
	}
	return (dest);
}
