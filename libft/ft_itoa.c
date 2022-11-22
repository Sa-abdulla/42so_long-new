/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:13:00 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/24 22:54:24 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int num)
{
	int	l;

	l = 0;
	while (num)
	{
		num = num / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
		sign = -1;
	i = (n <= 0) + len(n);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (sign == -1)
		ptr[0] = '-';
	else if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		ptr[--i] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (ptr);
}
