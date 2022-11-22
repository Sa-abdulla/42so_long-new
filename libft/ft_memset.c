/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:34:39 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/20 21:42:03 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*byte;

	i = 0;
	byte = ((unsigned char *)b);
	while (i < len)
	{
		byte[i] = (unsigned char)c;
		i++;
	}
	return (byte);
}
