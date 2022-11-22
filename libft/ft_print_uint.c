/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:43:28 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:46:49 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_pt(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa_pt(unsigned int n)
{
	char	*num;
	int		i;

	i = ft_len_pt(n);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (!num)
		return (0);
	num[i] = '\0';
	while (n != 0)
	{
		num[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (num);
}

int	ft_putuint_pt(unsigned int num)
{
	int		print_int;
	char	*n;

	n = 0;
	print_int = 0;
	if (n == 0)
		print_int = print_int + write(1, "0", 1);
	else
	{
		n = ft_uitoa_pt(num);
		print_int = print_int + ft_putstr_pt(n);
		free(n);
	}
	return (print_int);
}
