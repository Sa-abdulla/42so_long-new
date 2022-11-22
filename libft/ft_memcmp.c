/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:24:14 by sabdulla          #+#    #+#             */
/*   Updated: 2021/12/26 16:57:22 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			d;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	d = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (str1[i] != str2[i])
		{
			d = (str1[i] - str2[i]);
			return (d);
		}
		i++;
		n--;
	}
	return (d);
}
