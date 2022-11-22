/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:17:17 by sabdulla          #+#    #+#             */
/*   Updated: 2021/12/29 14:58:25 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*sr;
	int					diff;
	int					length;

	length = (int)len;
	diff = src - dst;
	if (dst == src)
		return (dst);
	if (diff > 0 && diff < length)
		return (ft_memcpy(dst, src, len));
	else
	{
		dest = dst + len - 1;
		sr = src + len - 1;
		while (len)
		{
			*dest-- = *sr--;
			len--;
		}
		dest++;
		sr++;
	}
	return (dest);
}
