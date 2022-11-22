/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:12:12 by sabdulla          #+#    #+#             */
/*   Updated: 2022/01/25 13:18:55 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)s;
	while (st[i])
	{
		if (st[i] != (unsigned char)c)
			i++;
		else if (st[i] == (unsigned char)c)
			return ((char *)(st + i));
	}
	if (st[i] == (unsigned char)c)
		return ((char *)(st + i));
	return (NULL);
}
