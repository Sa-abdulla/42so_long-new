/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:53:41 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/24 22:45:20 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = ft_strlen(s1);
	dst = (char *)malloc((sizeof(char)) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		dst[i] = *s1++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
