/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:23:39 by sabdulla          #+#    #+#             */
/*   Updated: 2021/12/29 11:20:37 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*st;

	i = 0;
	st = (char *)s;
	while (st[i])
		i++;
	if (!c)
		return (st + i);
	--i;
	if (!*st)
		return (0);
	while (i >= 0)
	{
		if (st[i] != (unsigned char)c)
			i--;
		else if (st[i] == (unsigned char)c)
			return ((char *)(st + i));
	}
	return (NULL);
}
